#include<bits/stdc++.h>
using namespace std;

char vow[] = {'a', 'e', 'i', 'o', 'u'};

int main(){
  char c; cin >> c;
  bool ans = false;
  for(int i = 0; i < 5; i++){
    if(c == vow[i]) ans = true;
  }
  cout << (ans?"vowel":"consonant") << endl;
}