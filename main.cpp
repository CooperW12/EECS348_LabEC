//Cooper Wright  Lab EC  EECS 348
//add to test/quiz grade

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double extractNumeric(const string& str){
  int length = str.length();
  double output;
  int index;
  bool pastDec = false; 
  int decDigits = 1;
  
  for (int i = 0; i < length; i++){
    index = length - 1 - i; //index is the length - 1 - i for right to left
    if (isdigit(str[index]) && not pastDec){ //if not past decimal (right to left)
      output += pow(10,i) * (str[index] - '0'); //add 10^index (for digit placement) * str[index] - '0' because it is reading the ascii value ('0'->48, '1'->49, '2'->50...)
      decDigits += 1;

    } else if (isdigit(str[index]) && pastDec){ //if past decimal (right to left)
      output += pow(10,(i-decDigits)) * (str[index] - '0'); //same as before but offset by -i to reset the 10^1 back to 1, 10, 100...

    } else if (str[index] == '-'){ 
      output *= -1; //multiply by -1 to make negative

    } else if (str[index] == '+'){ 
      output *= 1; //multiply by 1 to keep positive

    } else if (str[index] == '.'){
      output /= pow(10,i); //move to behind the decimal 
      pastDec = true; //flip value to use other if

    } else{
      return -999999.99;
    }
  }  

  return output;

}

int main(){
  string input;

  while (true){
    cout << "enter a string (or 'end' to quit): ";
    cin >> input;

    if (input == "end"){
      break;
    }

    double number = extractNumeric(input);

    if (number != -999999.99){
      cout << "the input is: " << fixed << setprecision(4) << number << endl;
  
    } else{
      cout << "the input is invalid" << endl;
    }

  }

  return 0;

}

