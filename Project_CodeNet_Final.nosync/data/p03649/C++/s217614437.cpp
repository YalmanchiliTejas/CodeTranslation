#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    ll ans=0;
    while(true){
        bool updated=false;
        rep(i,N){
            ll cnt=a[i]/N;
            if (cnt) updated=true;
            ans+=cnt;
            a[i]%=N;
            rep(j,N) if (j!=i) a[j]+=cnt;
        }
        if (!updated) break;
    }
    cout << ans << endl;
}