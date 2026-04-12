#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
  char c; cin >> c;
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
  return 0;
}
