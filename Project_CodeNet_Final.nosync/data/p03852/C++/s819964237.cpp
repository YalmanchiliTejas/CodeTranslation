#include<iostream>

#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)

using namespace std;

int main(){
  char c;
  cin >> c;
  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') cout << "vowel" << endl;
  else cout << "consonant" << endl;
  return 0;
}
