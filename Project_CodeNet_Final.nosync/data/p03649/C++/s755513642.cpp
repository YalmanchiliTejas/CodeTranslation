#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL a[50], b[50];

bool solve(LL x) {
    forn(i, n) b[i] = a[i] + x;
    forn(i, n) x -= (b[i] + 1) / (n + 1);
    return x >= 0;
}

int main() {
    cin >> n;
    forn(i, n) cin >> a[i];
    LL lo = 0, hi = 1e18, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (solve(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    lo = max(0ll, lo - 1000);
    while (!solve(lo)) ++lo;
    cout << lo << endl;
    return 0;
}
