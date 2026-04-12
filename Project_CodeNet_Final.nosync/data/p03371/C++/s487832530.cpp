#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = inff;
    ll q = 0;
    for (int i = 0; i <= 100000; i++) {
        ans = min(ans, i*2*c + (max(q, x-i)*a) + (max(q, y-i)*b));
    }

    cout << ans << endl;

    return 0;
}