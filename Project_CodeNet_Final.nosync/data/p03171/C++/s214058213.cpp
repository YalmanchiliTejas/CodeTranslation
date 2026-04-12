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
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld pi=3.141592653589793238;

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N,0);
    for(ll i=0;i<N;++i)cin>>a[i];
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, -1));
    function<ll(ll,ll)> solve=[&](ll x, ll y){
        if(dp[x][y]!=-1)return dp[x][y];
        if(x>=y)return dp[x][y]=0LL;
        //Taro first
        else if((y-x)%2==N%2){
            return dp[x][y]=max(a[x]+solve(x+1,y),a[y-1]+solve(x,y-1));
        }
        //Jiro first
        else {
            return dp[x][y]=min(-a[x]+solve(x+1,y),-a[y-1]+solve(x,y-1));
        }
    };
    prt(solve(0,N))

    return 0;
}
