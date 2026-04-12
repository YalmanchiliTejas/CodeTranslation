#include "bits/stdc++.h"
using namespace std;
using ll = long long; using pii = pair<int, int>;
const int MOD = (int)1e9 + 7, INF = (1 << 27); const ll INFLL = (1LL << 55);
#define FOR(i,a,b) for(int (i)=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
template<typename T, typename U> inline void chmax(T &x, U y) { if (x < y) x = y; }
template<typename T, typename U> inline void chmin(T &x, U y) { if (x > y) x = y; }

int n;
vector<int> a;

int main() {
    scanf("%d", &n);
    a.resize(n);
    rep(i, n) scanf("%d", &a[i]);

    auto b = a;
    sort(a.begin(), a.end());
    int x = a[n / 2];
    for (int i : b) {
        if (i < x) printf("%d\n", x);
        else printf("%d\n", a[n/2-1]);
    }

    return 0;
}
