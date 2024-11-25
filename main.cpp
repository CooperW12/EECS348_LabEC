//Cooper Wright  Lab EC  EECS 348


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



int main(){
  string input;

  while (true){
    cout << "enter a string (or 'end' to quit): ";
    cin >> input;

    if (input == "end"){
      break;
    }
  }


  return 0;



}

