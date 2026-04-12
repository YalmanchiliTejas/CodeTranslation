#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  for(int i=0;i<S.size();i++){
    if(S.at(i) == 'a' ||
       S.at(i) == 'i' ||
       S.at(i) == 'u' ||
       S.at(i) == 'e' ||
       S.at(i) == 'o'){
      cout << "vowel" << endl;
    }else{
      cout << "consonant" << endl;
    }
  }
}
