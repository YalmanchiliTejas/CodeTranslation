#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) sort((a).rbegin(), (a).rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n; 0 <= i; i--)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define FORSTEP(i, start, end, step) for (int i = start; i < end; i += step)
#define ALL(a) a.begin(), a.end()
typedef long long ll;
const int INF32 = 2147483647;
const ll INF64  = 9223372036854775807;
using namespace std;

// パティとバーガーの総数
ll p[50], a[50];

ll solve(int n, ll x) {
    if (n == 0 && x <= 0)
        return 0;
    else if (n == 0 && x == 1)
        return 1;
    else if (x <= 1 + a[n - 1])
        return solve(n - 1, x - 1);
    else if (x == 2 + a[n - 1])
        return p[n - 1] + 1;
    else if (x <= 2 + 2 * a[n - 1])
        return p[n - 1] + 1 + solve(n - 1, x - 2 - a[n - 1]);
    else
        return 2 * p[n - 1] + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    ll X;
    cin >> N >> X;

    p[0] = 1;
    a[0] = 1;

    FOR(i, 1, N) {
        p[i] = 2 * p[i - 1] + 1;
        a[i] = 2 * a[i - 1] + 3;
    }

    ll ans = solve(N, X);

    cout << ans << endl;

    return 0;
}