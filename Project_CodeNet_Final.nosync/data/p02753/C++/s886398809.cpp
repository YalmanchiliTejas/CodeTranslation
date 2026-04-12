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
    string S; cin >> S;
    if(count(S.begin(), S.end(), 'A') && count(S.begin(), S.end(), 'B')) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}