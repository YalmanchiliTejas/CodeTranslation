#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

// https://www.hamayanhamayan.com/entry/2020/02/09/225141

string s;
ll K;
ll dp[101][2][5]; // i桁目まで確定していて、現時点でs以下であるかがjという状態で、0でない数字がk個ある数の個数

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  cin>>s>>K;
  ll n=s.size();
  
  dp[0][0][0]=1;
  rep(i,n) rep(j,2) rep(k,K+1){
    ll num=s[i]-'0';
    rep(nxt,10){
      if(num<nxt && j==0) continue; // s未満であることが未確定で、現在見ている桁より大きい値を採用することはできない
      
      ll nj=j;
      if(nxt<num) nj=1; // 今見ている桁より小さい値を採用するなら、以降はs未満であることが確定する
      ll nk=k;
      if(nxt!=0) nk++;
      dp[i+1][nj][nk]+=dp[i][j][k];
    }
  }
  ll ans=dp[n][0][K]+dp[n][1][K];
  cout<<ans<<endl;
}