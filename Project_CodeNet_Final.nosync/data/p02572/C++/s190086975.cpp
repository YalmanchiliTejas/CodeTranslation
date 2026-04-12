#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n) cin >> a[i];
    b[n-1] = 0;
    for(int i=n-1; i>0; --i){
        b[i-1] = b[i]+a[i];     
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
        ll now = (a[i]*(b[i]%MOD))%MOD;
        ans = (ans+now)%MOD;
    }

    cout << ans << endl;
    return 0;
}