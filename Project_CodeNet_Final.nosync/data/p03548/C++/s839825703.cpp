#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5 + 5, INF = 5 << 28, MOD = 1e9 + 7;

int N, M, K;
vector<int> A, B;
string S, T;

void input() {
  int x, y, z;
  cin>>N>>M>>K;
  ;
}
void solve() {
  int ans = 0;
  if (N>=M+K){
    ans++;
    N -= M+K;
    N -= K;
  }

  ans += (N/(M+K));
  cout<<ans<<endl;

  ;
  ;
}
signed main() {
  input();
  solve();
  return 0;
}