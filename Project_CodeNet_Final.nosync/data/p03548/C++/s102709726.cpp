#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f;
typedef vector<ll> vll;
typedef pair<ll, ll> Pll;

ll N;

int main() {
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    ll ans = (X - Z) / (Y + Z);
    cout << ans << endl;
    return 0;
}