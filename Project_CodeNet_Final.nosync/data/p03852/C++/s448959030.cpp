#include<iostream>
using namespace std;
#include<vector>
#include<string>
 
int main(){
  string s = "aioeu";
  string c;
  cin >> c;
  if(s.find(c) != string::npos){
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}