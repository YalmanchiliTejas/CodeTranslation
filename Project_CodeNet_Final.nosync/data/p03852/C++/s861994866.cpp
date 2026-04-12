#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main(){
  char c;
  cin >> c;

  if(c == 'a') cout << "vowel" << endl;
  else if(c == 'e') cout << "vowel" << endl;
  else if(c == 'i') cout << "vowel" << endl;
  else if(c == 'o') cout << "vowel" << endl;
  else if(c == 'u') cout << "vowel" << endl;
  else cout << "consonant" << endl;

  return 0;
}
