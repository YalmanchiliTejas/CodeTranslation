#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  char s;
  cin >> s;
  if(s == 'a' || s == 'e' || s == 'i' || s == 'o'||s=='u') {
    cout << "vowel" << endl;
  }else {
    cout << "consonant" << endl;
  }
}