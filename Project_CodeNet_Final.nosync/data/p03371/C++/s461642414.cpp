#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int ulim = max(X, Y)*2;
    ll ans = LLINF;
    for(int ab = 0; ab <= ulim; ab++){
        ll remA = max(0ll, X - ab/2);
        ll remB = max(0ll, Y - ab/2);
        ans = min(ans, remA*A + remB*B + ab*C);
    }
    cout << ans << endl;
    return 0;
}