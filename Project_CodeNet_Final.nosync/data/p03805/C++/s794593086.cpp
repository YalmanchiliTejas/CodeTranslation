// https://atcoder.jp/contests/abc054/tasks/abc054_c
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef set<int> IntSet;
typedef set<int, greater<int>> IntRevSet;

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

int n, m;
vector<int> v[1000];
int rec(int now, set<int> his) {
    int ans = 0;
    if (his.size() == n) {
        return 1;
    }
    for (auto x : v[now]) {
        if (his.count(x) == 0) {
            set<int> t = his;
            t.insert(x);
            ans += rec(x, t);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> n >> m;
    REP(i, m) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    set<int> his;
    his.insert(1);
    cout << rec(1, his) << endl;
    return 0;
}
