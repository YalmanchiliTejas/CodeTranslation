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
#define FOR(i, a, b) for(int i= (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

// constant
// -----------------------------------------------------------------------------
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

// debug
// -----------------------------------------------------------------------------
#define DUMP(x)  cerr << #x << " = " << (x) << endl


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int n; cin >> n;
    vector<int> A(26, INF);
    REP(i, n) {
        string S; cin >> S;
        vector<int> tmp(26, 0);
        REP(j, S.length()) {
            tmp[S[j] - 'a']++;
        }
        REP(j, 26) {
            A[j] = min(A[j], tmp[j]);
        }
    }
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string ans = "";
    REP(i, 26) {
        REP(j, A[i]) {
            ans += alpha[i];
        }
    }
    cout << ans << "\n";
}