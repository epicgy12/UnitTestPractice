#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  if (phrase.length() == 0) return 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string phrase){
  bool upper = false;
  bool lower = false;
  int index = 0;
  if (phrase.length() == 0) return false;
  while(index < phrase.length() - 1){
    if (isupper(phrase[index])) upper = true;
    if (islower(phrase[index])) lower = true;
    if (upper && lower) return true;
    index++;
  }
  return false;
}

Password::Password(){
  pass_history.push_back("ChicoCA-95929");
}

/*receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long, but no longer than 20
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history*/
void Password::set(string phrase){
  if (phrase.size() >= 8){
    if (count_leading_characters(phrase) <= 3){
      if (has_mixed_case(phrase)){
        if (true){
          pass_history.push_back(phrase);
        }
      }
    }
  }
}


bool Password::authenticate(string phrase){
  int index = 0;
  bool go = true;
  //matching characters between phrase and history
  while( go ){
    if ( phrase[index] == pass_history[pass_history.size()-1][index] ){
      go = false;
    }
    index++;
    if (index == phrase.length()-1) break;
  }
  return !go;
}