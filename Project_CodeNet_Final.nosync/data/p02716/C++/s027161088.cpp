#include <bits/stdc++.h>
using namespace std;

typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;
typedef vector< vector< vector<ll> > > vvvint;
typedef vector<string> vstring;
typedef vector< vector<string> > vvstring;
typedef vector<char> vchar;
typedef vector< vector<char> > vvchar;
typedef vector<long double> vdouble;
typedef vector< vector<long double> > vvdouble;
typedef vector< vector< vector<long double> > > vvvdouble;
typedef pair<ll,ll> pint;
typedef vector<pint> vpint;
typedef vector<bool> vbool;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ALL(obj) (obj).begin(), (obj).end()
// #define LLONG_MAX 9223372036854775806
#define vmax(vec) *max_element(vec.begin(), vec.end())
#define vmin(vec) *min_element(vec.begin(), vec.end())
#define vsort(vec) sort(vec.begin(), vec.end())
#define vsortgr(vec) sort(vec.begin(), vec.end(), greater<ll>())
#define MOD 1000000007
// #define MOD 998244353
// #define MOD LLONG_MAX
const double PI=3.14159265358979323846;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0,};

void printv(vint &v){
    for(auto e:v) cout<<e<<" ";
        cout<<endl;
    }

// 繰り返し二乗法
ll power(ll a, ll b){
    if(a==1)return a;
    // if(a==0)re
    ll res=1;
    while(b>0){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

const int MAX=2100000;

ll fact[MAX], fact_inv[MAX];

void init_fact(ll n){
    fact[0]=1;
    // 階乗の計算
    for(ll i=0; i<n; i++) fact[i+1]=fact[i]*(i+1)%MOD;
    fact_inv[n]=power(fact[n], MOD-2);
    // 逆元の計算
    for(ll i=n-1;i>=0;i--) fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;
}

ll comb(ll n, ll r){
    return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}

ll perm(ll n, ll r){
    return (fact[n]*fact_inv[n-r])%MOD;
}

int main() {
    cout<<fixed<<setprecision(10);

    ll n; cin>>n;
    vint a(n); rep(i,n) cin>>a[i];

    const ll neginf = -(1e9*3e5);

    if(n%2==0){
        vvint dp(n+2,vint(2, neginf));
        dp[0][0] = 0;
        rep(i,n){
            if(dp[i][0] > neginf){
                chmax(dp[i+2][0], dp[i][0]+a[i]);
                chmax(dp[i+3][1], dp[i][0]+a[i]);
                chmax(dp[i+1][1], dp[i][0]);
            }
            if(dp[i][1] > neginf){
                chmax(dp[i+2][1], dp[i][1]+a[i]);
            }
        }

        cout<<max(dp[n][1], dp[n+1][1]);

    }else{
        vvint dp(n+2,vint(3, neginf));
        dp[0][0] = 0;
        rep(i,n){
            if(dp[i][0] > neginf){
                if(i!=n-3) chmax(dp[i+2][0], dp[i][0]+a[i]);
                chmax(dp[i+3][1], dp[i][0]+a[i]);
                chmax(dp[i+4][2], dp[i][0]+a[i]);

                chmax(dp[i+1][1], dp[i][0]);
            }
            if(dp[i][1] > neginf){
                chmax(dp[i+2][1], dp[i][1]+a[i]);
                chmax(dp[i+3][2], dp[i][1]+a[i]);

                chmax(dp[i+1][2], dp[i][1]);
            }
            if(dp[i][2] > neginf){
                chmax(dp[i+2][2], dp[i][2]+a[i]);
            }
        }
        cout<<max(dp[n][2], dp[n+1][2]);

    }

    return 0;

}