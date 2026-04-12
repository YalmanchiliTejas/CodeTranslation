#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<int> id(m, -1);
    vector<int> a;
    int len = 0;
    ll tot = 0;
    while (id[x] == -1) {
        a.push_back(x);
        id[x] = len;
        len++;
        tot += x;
        x = x * x % m;
    }
    int c = len - id[x];
    ll sum = 0;
    rep2(i, id[x], len) {
        sum += a[i];
    }

    ll ans = 0;
    if (n <= len) {
        rep(i, n) {
            ans += a[i];
        }
    } else {
        ans += tot;
        n -= len;
        ans += sum * (n / c);
        n %= c;
        rep(i, n) {
            ans += a[id[x] + i];
        }
    }
    cout << ans << endl;
    return 0;
}

// int main() {
//     ll n, x, m;
//     cin >> n >> x >> m;
//     vector<ll> head, loop;
//     head.push_back(x);
//     ll interval;
//     rep(i, n - 1) {
//         ll tmp = head[i] * head[i] % m;
//         auto it = find(head.begin(), head.end(), tmp);
//         if (it != head.end()) {
//             loop = vector<ll>(it, head.end());
//             interval = loop.size();
//             head.erase(it, head.end());
//             break;
//         }
//         head.push_back(tmp);
//     }
//     ll sum = 0;
//     for (auto e : head) {
//         sum += e;
//     }
//     if (!loop.size()) {
//         cout << sum << endl;
//         return 0;
//     }
//     cout << "head.size: " << head.size() << endl;
//     ll remain = n - head.size();
//     ll div = remain / loop.size();
//     ll mod = remain % loop.size();
//     for (auto e : loop) {
//         sum += div * e;
//     }
//     rep(i, mod) {
//         sum += loop[i];
//     }
//     cout << sum << endl;
//     cout << "interval: " << interval << endl;
//     cout << "head:" << endl;
//     for (auto e : head) {
//         cout << e << endl;
//     }
//     cout << "loop:" << endl;
//     for (auto e : loop) {
//         cout << e << endl;
//     }
//     return 0;
// }
