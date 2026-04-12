#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
    ll ans = LINF;
    for(ll i = 0; i <= 200000;i+=2){
        ans = min(ans,C*i + A*max(X-i/2,0LL) + B*max(Y-i/2,0LL));
    }
    cout << ans << endl;
    return 0;
}
