#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  char c;
  string vowel = "aeiou";
  int d = 0;
  cin >> c;
  rep(i,vowel.size()){
    if(c==vowel.at(i))
      d++;
  }
  if(d==0)
    cout << "consonant" << endl;
  else
    cout << "vowel" << endl;
}