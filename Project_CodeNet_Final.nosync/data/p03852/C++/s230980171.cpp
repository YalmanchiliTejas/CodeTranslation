#include<bits/stdc++.h>
using namespace std;

int main(){
  char c;
  cin >> c;
  
  string mother = "aiueo";
  int f=0,i;
  for(i=0;i<5;i++){
    if(c == mother[i])
      f=1;
  }
  if(f == 1)
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
  return 0;
}