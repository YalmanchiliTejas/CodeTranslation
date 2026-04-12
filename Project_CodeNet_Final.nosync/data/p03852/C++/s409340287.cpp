#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<math.h>
using namespace std;


int main() {
  string c;
  cin >> c;
  if((c == "a")||(c == "e")||(c == "i")||(c == "o")||(c == "u"))
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
}
