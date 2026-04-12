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

ll dp[105][2][5]; // i文字目までで、n以下であるかの状態がjで、0でない数字がk個あるような物の個数

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  string n; ll K; cin>>n>>K;
  ll N=n.size();
  
  dp[0][0][0]=1;
  rep(i,N) rep(j,2) rep(k,K+1){
    ll num=n[i]-'0';
    rep(nxt,10){
      if(nxt>num && j==0) continue;
      // if(i==0&&nxt==0) continue; <= 先頭桁が0は一見このように除外したくなるが誤り
      // nxt=0がN回続いて、dp[N][1][0]に格納されるのは1であり、これは0000...0つまり0という数字に対応している
      // 同様に例えば、dp[N][0 or 1][2]には、0000..0230つまり230に対応する場合も管理されているはずである
      // よって先頭桁0というのは、0以外の値が出るまで先頭に何もない、を意味するだけでdpがカウントする数字は辻褄が合う
      
      ll nj=j;
      if(nxt<num) nj=1;
      ll nk=k;
      if(nxt!=0) nk++;
      dp[i+1][nj][nk]+=dp[i][j][k];
    }
  }
  
  ll ans=dp[N][0][K]+dp[N][1][K];
  cout<<ans<<endl;
}
