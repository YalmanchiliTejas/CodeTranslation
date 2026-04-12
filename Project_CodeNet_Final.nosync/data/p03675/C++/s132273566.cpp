#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
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
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, 0, N) cin >> a[i];

  if (N == 1) {
    cout << a[0] << endl;
    return;
  }

  vector<int> odds, evens;
  rep(i, 0, N) {
    if (i%2 == 0) odds.push_back(a[i]);
    else evens.push_back(a[i]);
  }

  if (N%2 == 1) {
    reverse(all(odds));
    cout << odds[0];
    rep(i, 1, (int)odds.size())  cout << " " << odds[i];
    rep(i, 0, (int)evens.size()) cout << " " << evens[i];
  } else {
    reverse(all(evens));
    cout << evens[0];
    rep(i, 1, (int)evens.size()) cout << " " << evens[i];
    rep(i, 0, (int)odds.size())  cout << " " << odds[i];
  }
  cout << endl;
}