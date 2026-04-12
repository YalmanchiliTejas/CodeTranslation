#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1001001001;

int a[26];
int b[26];

int main(){
  int n;
  cin >> n;

  fill(b, b+26, INF);
  rep(i, n){
    string s; cin >> s;
    fill(a, a+26, 0);
    for(char c : s){
      a[c-'a']++;
    }
    rep(j, 26){
      chmin(b[j], a[j]);
    }
  }

  rep(i, 26){
    char c = 'a' + i;
    rep(j, b[i]) cout << c;
  }
  cout << endl;

  return 0;
}
