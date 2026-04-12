#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double eps = 0.00001;
const int MOD = 1000000007; //998244353
const int INF = 1070000055;
const long long LINF = 1223372000000000555;
const int N = 1050555;
const int M = 6525;

ll a[N];
ll suf[N];

void solve(){
    int n;
    cin >> n;

    ll sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = n; i >= 1; i--){
        suf[i] = suf[i+1] + a[i];
        suf[i] %= MOD;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ans += a[i] * suf[i+1];
        ans %= MOD;
    }

    cout << ans;

}


int main() {
    ios_base::sync_with_stdio(false);
#ifdef dddxxz
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else

#endif

    int T = 1;
    //cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}