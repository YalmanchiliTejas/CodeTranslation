#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rrep(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define fore(i,a) for(auto &i:a)
#define all(a) (a).begin(),(a).end()
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
using ll = long long; constexpr int inf = INT_MAX / 2; constexpr ll infl = 1LL << 60;
template<class T>void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class T>void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T>void POSS(T condition){ if(condition) cout << "POSSIBLE" << endl; else cout << "IMPOSSIBLE" << endl; }
template<class T>void Poss(T condition){ if(condition) cout << "Possible" << endl; else cout << "Impossible" << endl; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<class T>T gcd(T a, T b){ if(a && b){ return gcd(min(a, b), max(a, b) % min(a, b)); }else{ return a; }}
template<class T>T lcm(T a, T b){ return a / gcd(a, b) * b; }


void _main() {
  int N, K;
  string S;
  cin >> N >> S >> K;

  char c = S[K-1];
  rep(i, 0, N) if (S[i] != c) S[i] = '*';
  cout << S << endl;
}