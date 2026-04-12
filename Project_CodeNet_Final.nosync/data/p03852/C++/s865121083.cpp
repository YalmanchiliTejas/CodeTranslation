#include<bits/stdc++.h>
using namespace std;

string S;
char c;

int main(){
  
  cin >> S;

  c = S.at(0);
  if( c=='a' || c=='e' || c== 'i' || c=='o' || c=='u')
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;

  return 0;
}
