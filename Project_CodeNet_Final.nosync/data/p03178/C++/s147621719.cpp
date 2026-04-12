#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld pi=3.141592653589793238;



signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    string K;
    cin >> K;
    ll D;
    cin >> D;  
    ll n=K.size();
    //dp[i][j]はK[i]まで見て、余りがjであるもの
    vector<vector<ll>> dp0(n, vector<ll>(D, 0));
    vector<vector<ll>> dp1(n, vector<ll>(D, 0));
    vector<ll> k(n,0);
    for(ll i=0;i<n;++i){
        k[i]=K[i]-'0';
    }
    for(ll i=0;i<k[0];++i)dp1[0][i%D]++;
    dp0[0][k[0]%D]++;
    for(ll i=1;i<n;++i){
        for(ll j=0;j<D;++j){
            for(ll l=0;l<10;++l){
            if(l<k[i]){
                dp1[i][(j+l)%D]+=dp0[i-1][j]+dp1[i-1][j];
            }
            else if(l==k[i]){
                dp0[i][(j+l)%D]+=dp0[i-1][j];
                dp1[i][(j+l)%D]+=dp1[i-1][j];
            }
            else {
                dp1[i][(j+l)%D]+=dp1[i-1][j];
            }
            dp0[i][(j+l)%D]%=MOD;
            dp1[i][(j+l)%D]%=MOD;
            }
        }   
    }
    prt((dp0[n-1][0]+dp1[n-1][0]-1+MOD)%MOD)


    return 0;
}
