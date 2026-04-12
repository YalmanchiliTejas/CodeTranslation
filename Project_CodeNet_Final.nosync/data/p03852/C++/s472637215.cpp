#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
  string c;
  cin >> c;
  if(c == "a" || c == "i" || c == "u" || c == "e" || c == "o"){
    cout << "vowel";
  }
  else{
    cout << "consonant";
  }
  return 0;
}