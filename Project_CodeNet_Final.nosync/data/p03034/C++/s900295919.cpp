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
    ll N;
    cin >> N;
    vector<ll> s(N);
    rep(i,N) cin >> s[i];
    ll ans=0;
    rep2(i,1,N){
        ll sum=0;
        for (ll j=i;j<=N-1;j+=i){
            ll A=N-1-j,B=A-i;
            if (A<=B||B<=0) break;
            if (A%i==0&&A/i<=j/i) break;
            sum+=s[j]+s[N-1-j];
            chmax(ans,sum);
        }
    }
    cout << ans << endl;
}