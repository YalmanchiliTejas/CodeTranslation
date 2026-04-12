#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main(){
    ll n,x,m;cin >> n >> x >> m;
    if(n<=300000){
        ll ans=0;
        while(n--){
            ans+=x;
            x=x*x%m;
        }
        cout << ans <<endl;return 0;
    }
    vector<ll> memo(m+1,0);
    ll sum=0;
    ll loop=-1;
    ll now=0;
    rep(i,n){
        now++;
        if(memo[x]){
            loop=now-memo[x];
            break;
        }
        memo[x]=now;
        sum+=x;
        x=x*x%m;
    }
    //vl dp(loop);
    ll loopsum=0;
    rep(i,loop){
        loopsum+=x;
        x=x*x%m;
        //dp[0]=
    }
    now--;
    //cout << loop <<" " << loopsum << "  " << now <<" " << sum <<endl;
    sum+=(n-now)/loop*loopsum;
    ll need=(n-now)%loop;
    rep(i,need){
        sum+=x;
        x=x*x%m;
    }
    cout << sum <<endl;
}