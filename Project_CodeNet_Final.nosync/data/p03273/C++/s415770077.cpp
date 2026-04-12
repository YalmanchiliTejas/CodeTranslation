#include <bits/stdc++.h>
using namespace std;

// typedef
// -----------------------------------------------------------------------------
typedef long long ll;
typedef long double ld;

// container util
// -----------------------------------------------------------------------------
#define ALL(c)  (c).begin(),(c).end()
#define SZ(c) ((ll)(c).size())
#define MAX(c) *max_element(ALL(c))
#define MIN(c) *min_element(ALL(c))
#define SORT(c) sort((c).begin(),(c).end())

// repetition
// -----------------------------------------------------------------------------
#define FOR(i, a, b) for(ll i= (a); i < (ll)(b); ++i)
#define REP(i, n) FOR(i, 0, n)

// constant
// -----------------------------------------------------------------------------
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

// debug
// -----------------------------------------------------------------------------
#define DUMP(x)  cerr << #x << " = " << (x) << endl


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int H, W; cin >> H >> W;
    string A[H];
    vector<int> skip_h, skip_w;
    REP(i, H) cin >> A[i];
    REP(i, H) {
        if (count(A[i].begin(), A[i].end(), '#') == 0) {
            skip_h.push_back(i);
        }
    }
    REP(j, W) {
        bool is_skip = true;
        REP(i, H) {
            if (A[i][j] == '#') {
                is_skip = false;
            }
        }
        if (is_skip) {
            skip_w.push_back(j);
        } 
    }

    REP(i, H) {
        if (find(skip_h.begin(), skip_h.end(), i) != skip_h.end()) {
            continue;
        }
        REP(j, W) {
            if (find(skip_w.begin(), skip_w.end(), j) != skip_w.end()) {
                continue;
            }
            cout << A[i][j];
        }
        cout << "\n";
    }
}