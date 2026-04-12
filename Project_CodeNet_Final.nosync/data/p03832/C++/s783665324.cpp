#include <bits/stdc++.h>
using namespace std;
#define int long long   // aaaaaaaaaaaaaaaaaa
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define SIZE(buff) (sizeof(buff)/sizeof(buff[0]))
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<pair<int,int>> VPII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void chmin(int64_t& a, int64_t b){
    a = min(a, b);
}
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
template<typename T, typename U>ostream& operator << (ostream& os, pair<T, U>& pair_var)
{os << "(" << pair_var.first << ", " << pair_var.second << ")";return os;}
// head
int q,m,n,k,res,tmp,tmp2,tmp3;
//int a[100001] = {};
//int b[100010] = {};
int a,b,c,d;
deque<PII> que;
string s;
VPII kukan[100002];
int dp[1005][1005];

const int CMAX = 2000000;
long long fact[CMAX] = {};
long long revFact[CMAX] = {};
void setFact(int N)
{
  fact[0] = 1;
  for (int i = 1; i<N; i++)
  {
    fact[i] = fact[i-1]*i;
    fact[i] %= mod;
  }
  revFact[N-1] = powmod(fact[N-1],mod-2);
  for (int i=N-2;i>=0;i--)
  {
    revFact[i] = revFact[i+1]*(i+1);
    revFact[i] %= mod;
  }
}

long long getC(int a, int b)
{
  return (((fact[a] * revFact[b]) % mod) * revFact[a-b]) % mod;
}

signed main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
	std::cin >>n>>a>>b>>c>>d;
    dp[0][0] = 1;
    setFact(n*2);
    rep(i,1,n+1){
        int wari = powmod(revFact[i],c-1);
        if (a<= i && i <= b){
        rep(j,c,d+1){
            wari *= revFact[i];
            wari %= mod;
            rep(k,0,n+1){
                if(k + j*i <=n){
                    dp[i][k+j*i] += (dp[i-1][k] * getC(n-k,j*i))%mod * fact[j*i]%mod * revFact[j]%mod*wari;
                    dp[i][k+j*i] %= mod;
                }
            }
        }
        }
        rep(j,0,n+1){
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
        }
    }
    cout<<dp[n][n]<<endl;
//    rep(i,0,n+1){
 //       rep(j,0,n+1){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<< endl;
//    }
}