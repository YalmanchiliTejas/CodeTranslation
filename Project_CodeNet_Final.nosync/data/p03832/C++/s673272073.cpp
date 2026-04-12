#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<29
#define LINF LLONG_MAX/3
#define mp make_pair
#define pb push_back
#define EB emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
constexpr double eps = 1e-14; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

constexpr int MAXN = 1010;

ll N,A,B,C,D;

ll dp[MAXN][MAXN];

ll fact[MAXN],fact_inv[MAXN];

ll mod_pow(ll x,ll n,ll mod){
    ll ret=1;
    while(n){
        if(n&1) ret = (ret *x) % mod;
        x = (x*x) % mod;
        n >>= 1;
    }
    return ret;
}

void init(){
    fact[0] = 1;
    for(int i=1;i<MAXN;i++) fact[i] = (fact[i-1]*i) % mod;
    for(int i=0;i<MAXN;i++) fact_inv[i] = mod_pow(fact[i],mod-2,mod);
}

int main(){
    scanf("%lld%lld%lld%lld%lld",&N,&A,&B,&C,&D);

    init();

    dp[0][A] = 1;

    for(int i=0;i<=N;i++){
        for(int j=A;j<=B;j++){
            if(dp[i][j] <= 0) continue;

            dp[i][j+1] += dp[i][j]; // k=0
            dp[i][j+1] %= mod;

            for(int k=C;k<=D;k++){
                int nxt = i+j*k;
                if(nxt>N) break;
                ll t = dp[i][j];
                t = (t*fact[N-i]) % mod;
                t = (t*fact_inv[N-i-j*k]) % mod;
                t = (t * fact_inv[k]) % mod;
                t = (t * mod_pow(fact_inv[j],k,mod)) % mod;
                dp[nxt][j+1] += t;
                dp[nxt][j+1] %= mod;
            }
        }
    }

    //for(int i=0;i<N+1;i++){
    //    for(int j=0;j<B+2;j++){
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    printf("%lld\n",dp[N][B+1]);
}
