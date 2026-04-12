#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
struct edge{ll to,cost;};
const int inf = 1<<28;
const ll INF = 1LL<<53;
const int COMBMAX = 500005;
const ll MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
#define repf(i,n) for(int i=0;i<=n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define eachdo(v, e) for(const auto& e : v)
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (ll)distance(v.begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (ll)distance(v.begin(), upper_bound((v).begin(), (v).end(), e))
ll mpow(ll a, ll n,ll mod=MOD){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
template<class T1, class T2> ll bcount(T1 v, T2 a){return upper_index(v,a)-lower_index(v,a);} 
template<class T> bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
template<class T> void debug2(T v){rep(i,v.size()){rep(j,v[i].size())cout<<v[i][j]<<" ";cout<<endl;}}
template<class T> void rdv(T &v){rep(i,v.size())cin>>v[i];}
template<class T> void rdvv(T &v){rep(i,v.size()){rep(j,v[i].size())cin>>v[i][j];}}

struct mint {
ll x;
    mint(ll x=0):x((x%MOD+MOD)%MOD){}
    mint& operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}
    mint& operator-=(const mint a) {if ((x += MOD-a.x) >= MOD) x -= MOD;return *this;}
    mint& operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}
    mint operator+(const mint a) const {mint res(*this);return res+=a;}
    mint operator-(const mint a) const {mint res(*this);return res-=a;}
    mint operator*(const mint a) const {mint res(*this);return res*=a;}
    mint pow(ll t) const {if (!t) return 1;mint a = pow(t>>1);a *= a;if (t&1) a *= *this;return a;}
    mint inv() const {return pow(MOD-2);}
    mint& operator/=(const mint a) {return (*this) *= a.inv();}
    mint operator/(const mint a) const {mint res(*this);return res/=a;}
};

struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (COMBMAX < n){
            mint ret = 1;
            rep1(i,k){
                ret *= (n-i+1);
                ret /= i;
            }
            return ret;
        }
        return fact[n]*ifact[k]*ifact[n-k];
    }
} ;//com(COMBMAX);

int main(){
    string K;
    ll D;
    cin >> K >> D;
    ll N = K.size();
    vector<vector<vector<mint>>> dp(N+1,vector<vector<mint>>(2,vector<mint>(D,0)));
    dp[0][0][0] = 1;
    rep(i,N)rep(sml,2)rep(m,D)rep(x,10){
        ll n = K[i] - '0';
        if(sml == 0){
            if(x<n){
                dp[i+1][1][(m+x)%D] += dp[i][sml][m];
            }else if(x==n){
                dp[i+1][0][(m+x)%D] += dp[i][sml][m];
            }
        }else{
            dp[i+1][1][(m+x)%D] += dp[i][sml][m];
        }
    }
    cout << (dp[N][0][0].x + dp[N][1][0].x - 1 + MOD)%MOD << endl;
}