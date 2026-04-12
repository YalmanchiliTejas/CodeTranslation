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
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

const int MAX = 55;
ll N, A[MAX];

ll solve() {
    ll res = 0;
    REP (q, 5e6) {
        REP (i, N) if (A[i] >= N) {
            ll temp = A[i]/N;
            res += temp;
            A[i] -= temp*(N+1);
            REP (j, N) A[j] += temp;
        }
    }
    return res;
}

int main() {
    cin >> N;
    REP (i, N) cin >> A[i];
    cout << solve() << endl;
}