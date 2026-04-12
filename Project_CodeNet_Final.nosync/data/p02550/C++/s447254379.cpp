#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
const ul mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> g(m, -1);
    ll now = x % m;
    ll loop_point;
    while (true) {
        ll next = now * now % m;
        if (g[next] != -1) {
            g[now] = next;
            loop_point = next;
            break;
        } else {
            g[now] = next;
            now = next;
        }
    }

    ll loop_size = 0, loop_sum = 0;
    ll point = loop_point;
    while (true) {
        loop_size++;
        loop_sum += point;
        if (g[point] == loop_point) {
            break;
        } else {
            point = g[point];
        }
    }

    ll ans = 0;
    point = x % m;
    while (point != loop_point && n != 0) {
        ans += point;
        point = g[point];
        n--;
    }
    ans += loop_sum * (n / loop_size);
    n %= loop_size;
    point = loop_point;
    while (n != 0) {
        ans += point;
        point = g[point];
        n--;
    }
    cout << ans << endl;
    return 0;
}

