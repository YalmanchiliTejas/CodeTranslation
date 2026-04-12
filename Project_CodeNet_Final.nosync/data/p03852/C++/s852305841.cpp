#include<bits/stdc++.h>
using namespace std;
int main(){
  char c;
  cin >> c;
  string str="aiueo";
  for(int j=0;j<5;j++)
    if(c == str.at(j)){
      cout << "vowel" << endl;
      return 0;
    }
  cout << "consonant" << endl;
}