#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 1e18;
    c *= 2;

    for(int i = 0; i <= 100000; i++) {
        ll now = 0;
        now += c * i;
        now += max(0, x-i) * a;
        now += max(0, y-i) * b;
        ans = min(ans, now);
    }

    cout << ans << endl;

    return 0;
}