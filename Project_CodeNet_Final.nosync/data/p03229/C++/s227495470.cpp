#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const ll MAX_N = ll(1e5 + 5);
const double EPS = 1e-10;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

int main() {
    ll n, a[MAX_N], ans = 0, ans2 = 0;
    cin >> n;
    REP(i, n) cin >> a[i];
    sort(a, a + n);
    ans += abs(a[n - 1] - a[0]);

    int pr = 0;
    for (int i = 0; i < n / 2; i++) {
        int j = i/2 + 1;
        int nx = (i%2 == 0 ? n - j*2 : j*2);
        if (nx == pr) break;
        if (nx == n/2 && n%2 == 1) break;
        ans += abs(a[nx] - a[pr]);
        pr = nx;
    }
    pr = n - 1;
    for (int i = 0; i < n / 2; i++) {
        int j = i / 2 + 1;
        int nx = (i % 2 == 1 ? n - j * 2 : j * 2) - 1;
        if (nx == n / 2 && n % 2 == 1) break;
        if (nx == pr) break;
        ans += abs(a[nx] - a[pr]);
        pr = nx;
    }
    if (n % 2 == 1)
        ans += max(abs(a[n / 2 + 1] - a[n / 2]), abs(a[n / 2 - 1] - a[n / 2]));



    cout << max(ans,0ll) << endl;
    return 0;
}
