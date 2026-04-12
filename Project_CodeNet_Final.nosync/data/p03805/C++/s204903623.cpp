#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
int const inf = 1<<29;

int main() {
  int N, M; cin >> N >> M;
  vector<map<int, int>> g(N);
  rep(i, M) {
    int a, b; cin >> a >> b;
    g[a-1][b-1] = g[b-1][a-1] = 1;
  }
  vector<int> ns(N); iota(ns.begin(), ns.end(), 0);
  int count = 0;
  do {
    if (ns[0] != 0) continue;
    bool ok = 1;
    rep(i, N - 1) {
      if (!g[ns[i]][ns[i + 1]]) {
        ok = 0;
      }
    }
    count += ok;
  } while (next_permutation(ns.begin(), ns.end()));
  cout << count << "\n";
}
