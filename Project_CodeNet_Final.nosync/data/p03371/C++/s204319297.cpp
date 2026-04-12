#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;

int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
//------------------------------------------------------------------------------------------------------------------------------

int main(void) { 
    ll A, B, C, X, Y;
    ll MAX = 400000;
    ll ans = INF;
    cin >> A >> B >> C >> X >> Y;
    for(ll i = 0; i <= MAX; i++) {
        int x = max(0LL, X - i / 2);
        int y = max(0LL, Y - i / 2);
        ans = min(ans, A * x + B * y + C * i);
    }
    cout << ans << endl;
}
