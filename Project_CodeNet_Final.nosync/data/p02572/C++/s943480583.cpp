#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define REP(i,a,b) for(int i=int(a);i<(int)b;++i)
#define Graph vector<vecctor<ll>>
#define pairs vector<pair<ll,ll>>
#define pb push_back



using namespace std;
using ll = long long;
const ll INF = 1e18;
const double PI = acos(-1);

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

const ll mod = 1e9+7;

int main(void)
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll>a(n);
    ll sum = 0,sum2 = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
        sum2 += a[i]*a[i];
        sum %= mod;
        sum2 %= mod;
    }
    ll ans = sum*sum-sum2;
    if(ans%2 == 0){
        ans = ans/2%mod;
    }else{
        ans += mod;
        ans = ans/2%mod;
    }

    cout << ans << endl;
    
    



    return 0;
}
