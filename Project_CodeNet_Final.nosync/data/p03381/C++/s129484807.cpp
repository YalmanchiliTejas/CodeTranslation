#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define frep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int inf = 1e9 + 9;
const ll linf  = 1ll * inf * inf;
const int N = 500000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);

int a[N];
int n;

vii b;

void solve() {
    cin >> n;
    rep(i, 0, n) {
        scanf("%d", a + i);
        b.push_back({a[i], i});
    }
    sort(b.begin(), b.end());

    rep(i, 0, n) {
        if (i < n / 2) a[b[i].second] = b[n / 2].first;
        else a[b[i].second] = b[n / 2 - 1].first;
    }

    rep(i, 0, n) printf("%d\n", a[i]);
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
#endif
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    for(int i = 0; i < Test; ++i) {
        //		printf("Case #%d: ", i + 1);
        solve();
    }
#ifdef _LOCAL_
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}
