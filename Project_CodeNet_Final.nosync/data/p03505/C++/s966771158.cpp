#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

ll k, a, b;

int main(){
    cin >> k >> a >> b;
    k -= a;
    ll ans = 1;
    if (k <= 0) {
        cout << ans << endl;
        return 0;
    }
    if (a <= b) {
        cout << -1 << endl;
        return 0;
    }
    cout << 1 + 2 * (k/(a-b) + (k%(a-b)>0)) << endl;
}






























