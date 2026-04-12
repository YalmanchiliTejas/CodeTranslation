#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

int main() {
  int N; string S;
  cin >> N >> S;
  S += S.substr(0,2);
  for (string s:{"SS","SW","WS","WW"}) {
    rep2(i,2,N+2) {
      if (s.substr(i-2,2)=="SS") {
        if (S[i-1]=='o') s+="S";
        else s+="W";
      }
      else if (s.substr(i-2,2)=="SW") {
        if (S[i-1]=='o') s+="W";
        else s+="S";
      }
      else if (s.substr(i-2,2)=="WS") {
        if (S[i-1]=='o') s+="W";
        else s+="S";
      }
      else {
        if (S[i-1]=='o') s+="S";
        else s+="W";
      }
    }
    if (s.substr(0,2)==s.substr(N,2)) {
      cout << s.substr(0,N) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}