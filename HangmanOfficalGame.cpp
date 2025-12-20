#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cctype>

using namespace std;

struct Hnagman{
  char word[20];
  char guessed[26];
  int guessCount;
  int wrong;
};
void showTitle() {
    cout << "\n";
    cout << " _   _    _    _   _  ____ __  __    _    _   _ \n";
    cout << "| | | |  / \\  | \\ | |/ ___|  \\/  |  / \\  | \\ | |\n";
    cout << "| |_| | / _ \\ |  \\| | |  _| |\\/| | / _ \\ |  \\| |\n";
    cout << "|  _  |/ ___ \\| |\\  | |_| | |  | |/ ___ \\| |\\  |\n";
    cout << "|_| |_/_/   \\_\\_| \\_|\\____|_|  |_/_/   \\_\\_| \\_|\n";
    cout << "\n";
}
void drawHangman(int wrong){
const char*stages[] = {
" +---+\n     |\n     |\n     |\n    ===",
" +---+\n O   |\n     |\n     |\n    ===",
" +---+\n O   |\n |   |\n     |\n    ===",
" +---+\n O   |\n/|\\  |\n     |\n    ===",
" +---+\n O   |\n/|\\  |\n/    |\n    ===",
" +---+\n O   |\n/|\\  |\n/ \\  |\n    ==="
};
  cout << stages[wrong] << endl;
}
bool isGuessed(Hangman *h, char c){
for (int i=0; i<h->guessCount; i++)
  if(h->guessed[i] == c)
    return true;
return false;
}
bool wordComplete(Hangman *h){
for(int i=0; h->word[i]; i++)
  if(!isGuessed(h, h->word[i]))
    return false;
return true;
}
  
void showWord(struct Hangman *h){
for(int i=0; h->word[i]; i++){
if(strchr(h->guessed,h->word[i]))
  cout<< h->word[i]<< " ";
else
  cout << "_ ";
}
cout << endl;
}

void createWordfile(){
ofstream file("words.txt");
const char words [30][20] = {
        "hangman","computer","science","wizard","keyboard",
        "pointer","function","algorithm","variable","constant",
        "internet","network","database","monitor","mouse",
        "laptop","notebook","compiler","debugger","array",
        "recursion","condition","loop","binary","decimal",
        "operator","memory","storage","program","syntax"
};
  for (int i = 0; i<30;i++){
    file<<words[i]<<endl;
    file.close();
  }

void loadWord(char *word){
ifstream file("words.txt");
char words[50][20];
int count = 0;

while(file >> words[count]){
count++;
}
file.close;
strcpy(word, words[rand() % count]);

int main(){

  srand(time(0));
  createWordfile();   //Function to create file

  char chocie;
  do {
      system("cls");  //Clear's the terminal screen
      showTitle();

    Hangman game{};
    loadWord(game.word);
    playGame(&game);

    cout<<"\nPlay again? (y/n) :";
    cin>>choice;
  }while(tolower(choice) =='y');

  cout<<"\nThanks for playing!\n"<<endl;
  
  return 0;  //end program
}


