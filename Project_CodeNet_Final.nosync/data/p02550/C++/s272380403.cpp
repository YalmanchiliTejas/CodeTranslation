#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    vector<ll>seen(m,-1);
    seen[x]=0;
    ll last = x;
    ll f=-1,s=-1;
    ll S = x;
    ll now;
    for(ll i=1;i<n;i++){
        now = (last*last)%m;
        if(seen[now]==-1){
            seen[now]=i;
            S += now;
            last = now;
        }
        else{
            f = seen[now];
            s = i;
            break;
        }
    }
    if(s==-1){
        cout << S << endl;
        return 0;
    }
    last = -1;
    ll ans = 0;

    rep(i,f){
        if(i==0){
            ans += x;
            last = x;
            continue;
        }
        now = (last*last)%m;
        ans += now;
        last = now;
    }
    ll rem = (n-f)%(s-f);
    ll p = 0;
    rep(i,s-f){
        if(last==-1){
            p += x;
            last = x;
            continue;
        }
        now = (last*last)%m;
        p += now;
        last = now;
    }

    rep(i,rem){
        if(last==-1){
            ans += x;
            last = x;
            continue;
        }
        now = (last*last)%m;
        ans += now;
        last = now;
    }
    ans += (n-f)/(s-f)*p;
    cout << ans << endl;
    return 0;
}
