#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    vector<int> a;
    set<int> b;
    int c;
    while (1) {
        if (b.find(x) != b.end()) {
            c = x;
            break;
        }
        a.push_back(x);
        b.insert(x);
        x = (x * x) % m;
    }
    ll sum = 0;
    ll sum2 = 0;
    int idx = -1;
    REP(i, a.size())
    {
        if (c == a[i]) {
            idx = i;
        }
        if (idx == -1)
            sum += a[i];
        else
            sum2 += a[i];
    }
    ll ans = 0;
    if (n < idx) {
        REP(i, n)
        {
            ans += a[i];
        }
    } else {
        ans += sum;
        n -= idx;
        ans += sum2 * (n / (a.size() - idx));
        REP(i, n % (a.size() - idx))
        ans += a[idx + i];
    }
    cout << ans << endl;
}