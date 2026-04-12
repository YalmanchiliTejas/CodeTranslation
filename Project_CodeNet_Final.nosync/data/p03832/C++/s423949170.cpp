#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};


ll dp[1001][1001];


const ll MaxN=201001;

ll f[MaxN], rf[MaxN];
ll inv(ll x) {
    ll res = 1;
    ll k = mod - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % mod;
        y = (y * y) % mod;
        k /= 2;
    }
    return res;
}
void init() {
    f[0] = 1;
    REP(i, 1, MaxN) f[i] = (f[i - 1] * i) % mod;
    REP(i, 0, MaxN) rf[i] = inv(f[i]);
}
//---------------------------------------------------------------------------------------------------
ll Com(ll n, ll k) {
    ll a = f[n]; // = n!
    ll b = rf[n-k]; // = (n-k)!
    ll c = rf[k]; // = k!

    ll bc = (b * c) % mod;

    return (a * bc) % mod;
}

int main(){
    ll N,A,B,C,D;
    cin>>N>>A>>B>>C>>D;
    init();
    dp[A-1][0]=1;
    REP(i,A,B+1) rep(k,N+1){
        for(ll j=0; k+j*i<=N; j++) {
            if(j==0) dp[i][k+j*i]=(dp[i][k+j*i]+dp[i-1][k])%mod;
            if(j>=C && j<=D) {
                ll ret=1;
                rep(h,j) ret=(ret*Com(N-k-h*i,i)%mod);
                ret=(ret*rf[j])%mod;
                dp[i][k+j*i]=(dp[i][k+j*i]+dp[i-1][k]*ret)%mod;
            }
        }
    }
    ll ans=0;
    /*REP(i,A-1,B+1) {
        cout<<i<<':';
        rep(j,N+1) cout<<dp[i][j]<<' ';
        cout<<endl;
    }*/
    cout<<dp[B][N]<<endl;
}