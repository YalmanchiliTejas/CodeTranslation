#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  string c="";
  string flag = "consonant";

  cin >> c;
  if((c == "a") || (c == "i") || (c == "u") || (c == "e") || (c == "o"))
    flag = "vowel";

  cout << flag << endl;
  return 0;
}