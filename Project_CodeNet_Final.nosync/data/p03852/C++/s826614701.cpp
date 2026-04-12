#include<iostream>
using namespace std;

int main(){
  string vowel = "aiueo";
  char c;	cin >> c;
  if(vowel.find(c) != -1){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }
  return 0;
}