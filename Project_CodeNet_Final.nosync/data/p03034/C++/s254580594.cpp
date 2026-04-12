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

const int MAX = 1e5+10;

int N;
ll s[MAX];

ll solve() {
    ll ans = 0;
    FOR (c, 1, N) {
        ll score = 0;
        ll k = 1;
        set<int> pos;
        while (k*c < N) {
            int a = N-1-k*c;
            int b = a-c;
            if (b <= 0 || b >= a) break;
            if (a == N-1-a || pos.find(a) != pos.end() || pos.find(N-1-a) != pos.end()) {
                break;
            }
            score += s[a];
            score += s[N-1-a];
            ans = max(ans, score);
            pos.insert(a);
            pos.insert(N-1-a);
            k++;
        }
    }
    return ans;
}

int main() {
    cin >> N;
    REP (i, N) cin >> s[i];
    cout << solve() << endl;
}