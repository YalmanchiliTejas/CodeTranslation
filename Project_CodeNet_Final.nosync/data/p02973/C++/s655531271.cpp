#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (int i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

const int MAX = 1e5+10;
const ll INF = 1e9+10;

ll N;
vi A;

ll solve() {
    multiset<int> m;
    m.insert(-1);
    FORE (a, A) {
        auto it = m.lower_bound(a);
        it--;
        if (*it != -1) m.erase(it);
        m.insert(a);
    }
    return m.size() - 1;
}

int main() {
    cin >> N;
    A = vi(N);
    REP (i, N) cin >> A[i];
    cout << solve() << endl;
}