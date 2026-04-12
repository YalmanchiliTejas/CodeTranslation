// https://atcoder.jp/contests/abc134/tasks/abc134_e

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define EPS (1e-9)
#define INF (1e9)
#define INFL (1e18)
#define MOD (1000000007)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOREACH(x, a) for (auto &(x) : (a))
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define LEN(x) (sizeof(x) / sizeof(*(x)))
// ll gcd(long a, long b) { return b ? gcd(b, a % b) : a; }
// ll lcm(long a, long b) { return a * b / gcd(a, b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    //差分が小さくなるように重ねる
    cin >> n;
    multiset<int> mp;
    REP(i, n) {
        cin >> t;
        auto it = mp.upper_bound(-t);
        // 検索値より小さい値が見つかったら削除する
        if (it != mp.end()) {
            mp.erase(it);
        }
        mp.insert(-t);
    }
    cout << mp.size() << endl;

    return 0;
}
