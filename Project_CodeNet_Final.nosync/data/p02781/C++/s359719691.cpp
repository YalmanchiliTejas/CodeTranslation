#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define debug2(x, y)                       \
  cerr << "(" << #x << "," << #y << ") = " \
       << "(" << x << "," << y << ")\n"
#define all(x) x.begin(), x.end()
#define each(a, x) for (auto& a : (x))
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define int long long
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
const int MX = 1e5 + 5, INF = 5LL << 57, MOD = 1e9 + 7;

string S;
vi va, vb;
int K;

void input() {
  ;
  ;
  cin>>S;
  cin>>K;

}
int dp[102][4][2];

int rec(int d=0, int k=0,bool tight=true){
  if (k>K){
    return 0;
  }
  if (d == S.size()){
    return  k==K;
  }
  int x = S[d]-'0';
  int r = (tight ? x : 9);
  int &res = dp[d][k][tight];
  if (~res) return res;
  res = 0;
  rep(i,0,r){

    res += rec(d+1, k + (i!=0), tight&&(i==r));
  }
  return res;
}
void solve() {
  int ans;
  memset(dp,-1,sizeof(dp));
  ans = rec(0,0,true);
  cout<<ans<<endl;

  ;
  ;
}
signed main() {
  input();
  solve();
  return 0;
}