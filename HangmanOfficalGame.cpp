#include<iostream>   //For input/ouput
#include<fstream>  //for file handlig
#include<cstdlib>  //For rand(), srand()        //HEADER FILES
#include<ctime>  //for time()
#include<cstring>  //for strcpy() & strchr()
#include<cctype>  //for tolower() and isalpha()

using namespace std;  //standard

//  STRUCTURE
// stores all game related data

struct Hangman{
  char word[20];  //word to guess
  char guessed[26];  //letters guessed
  int guessCount;  //number of guessed letters
  int wrong;  //number of wrong guesses
};

// DISPLAY TITLE
// ACSII art title
void showTitle() {
    cout << "\n";
    cout << " _   _    _    _   _  ____ __  __    _    _   _ \n";
    cout << "| | | |  / \\  | \\ | |/ ___|  \\/  |  / \\  | \\ | |\n";
    cout << "| |_| | / _ \\ |  \\| | |  _| |\\/| | / _ \\ |  \\| |\n";
    cout << "|  _  |/ ___ \\| |\\  | |_| | |  | |/ ___ \\| |\\  |\n";
    cout << "|_| |_/_/   \\_\\_| \\_|\\____|_|  |_/_/   \\_\\_| \\_|\n";
    cout << "\n";
}

// HANGMAN DRAWING'
//Draw hangman based on number of wrong guesses


void drawHangman(int wrong){
const char*stages[] = {
" +---+\n     |\n     |\n     |\n    ===",
" +---+\n O   |\n     |\n     |\n    ===",
" +---+\n O   |\n |   |\n     |\n    ===",
" +---+\n O   |\n/|   |\n     |\n    ===",
" +---+\n O   |\n/|\\  |\n     |\n    ===",
" +---+\n O   |\n/|\\  |\n/    |\n    ===",
" +---+\n O   |\n/|\\  |\n/ \\  |\n    ==="
};
  cout << stages[wrong] << endl;
}

//CHECK IF LETTER IS GUESSED
// returns true if letter already guessed

bool isGuessed(Hangman *h, char c){
for (int i=0; i<h->guessCount; i++)
  if(h->guessed[i] == c)
    return true;
return false;
}

  //CHECKS IF WORD IS COMPLETE
  //returns true if all letters are guessed

bool wordComplete(Hangman *h){
for(int i=0; h->word[i]; i++)
  if(!isGuessed(h, h->word[i]))
    return false;
return true;
}

//DISPLAY WORD
// shows the guessed letters and the underscores
  
void showWord(struct Hangman *h){
for(int i=0; h->word[i]; i++){
if(isGuessed(h,h->word[i]))
  cout<< h->word[i]<< " ";
else
  cout << "_ ";
}
cout << endl;
}

//CREATE A WORD FILE
//includes 30 words

void createWordFile(){
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
    file<<words[i]<<endl;  //saves words to file
  }
file.close();
}

  //LOADS RANDOM WORD
  //random word is selected from the file


void loadWord(char *word){
ifstream file("words.txt");
char words[50][20];
int count = 0;

while(file >> words[count]){
count++;
  }
  file.close();
  strcpy(word, words[rand() % count]);
}

    //GAME LOOP  (recursive)
//Main game logic
void playGame(Hangman *h){
  if(h->wrong >= 6){
  drawHangman(h->wrong);
  cout<<"\nYOU LOST! Word was: "<< h->word << endl;
  return ;
  }
  //Winning conditon
if(wordComplete(h)){
  cout<<"\nYOU WON!\n";
  return ;
}
 //Displays current game state
drawHangman(h->wrong);
showWord(h);

char ch;
cout<<"Guess a letter: ";
cin>>ch;
ch = tolower(ch);

  //Validate input (whether input is valid or not)
  if (!isalpha(ch)) {
    cout << "? Please enter a valid letter.\n";
    playGame(h);
    return;
}

  //Process guess
if(!isGuessed(h,ch)){
  h->guessed[h->guessCount++] = ch;
  if(!strchr(h->word,ch))
    h->wrong++;
  }
  playGame(h);  //Recursive 
}

int main(){  //Main program

  srand(time(0));  //seed random generator
  createWordFile();   //Function to create file

  char choice;
  do {
      system("cls");  //Clear's the terminal screen
      showTitle();

    Hangman game{};
    game.guessCount = 0;
    game.wrong = 0;

    loadWord(game.word);
    playGame(&game);

    cout<<"\nPlay again? (y/n) :";
    cin>>choice;
  }while(tolower(choice) =='y');

  cout<<"\nThanks for playing!\n"<<endl;  //Text after leaving game
  
  return 0;  //end program
}





