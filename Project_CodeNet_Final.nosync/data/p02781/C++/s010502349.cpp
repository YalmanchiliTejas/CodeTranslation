#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define per(i,n) for(ll i = n-1; i >= 0; i--)
#define REP(i,n) for(ll i = 1; i < n; i++)
#define PER(i,n) for(ll i = n; i >= 1; i--)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vs = vector<string>;
using vb = vector<bool>;
using vc = vector<char>;
using vcc = vector<vc>;
using vP = vector<P>;
using vPP = vector<vP>;
using vPl = vector<Pl>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// dp[i][smaller][j] = i桁目までで0以外の数字の個数がjのときの求める整数の個数
// ただしsmallerがtrueのときはNより小さい場合を考え、smallerがfalseならNと同じ場合を考える
ll dp[110][2][4] = {};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int k;
  cin >> s >> k;
  int n = sz(s);
  dp[0][false][1] = 1;
  dp[0][true][0] = 1;
  dp[0][true][1] = (s[0]-'0')-1;
  rep(i,n-1) {
    int ne = s[i+1] - '0';
    rep(j,k+1) {
      rep(x,10) {
        int nj = j;
        if(x) nj++;
        if(nj > k) continue;
        if(x < ne) dp[i+1][true][nj] += dp[i][false][j];
        if(x == ne) dp[i+1][false][nj] += dp[i][false][j];
        dp[i+1][true][nj] += dp[i][true][j];
      }
    }
  }
  cout << dp[n-1][false][k] + dp[n-1][true][k] << endl;
}