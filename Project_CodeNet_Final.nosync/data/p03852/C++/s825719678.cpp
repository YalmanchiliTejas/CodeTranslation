#include<bits/stdc++.h>
using namespace std;

int main(void){
  char a;
  cin >> a;
  
  if( a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
  
  return 0;
}