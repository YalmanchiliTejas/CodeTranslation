#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> cum(n);
    rep(i,n) cum[i]=a[i];
    for(int i=n-2;i>=0;i--) cum[i]=(cum[i]+cum[i+1])%MOD;
    //rep(i,n) cout << cum[i] << " ";
    //cout << endl;
    ll ans = 0;
    rep(i,n-1){
        ans += (a[i] * cum[i+1])%MOD; 
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}