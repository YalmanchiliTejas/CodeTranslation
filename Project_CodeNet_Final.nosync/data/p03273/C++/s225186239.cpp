#include "bits/stdc++.h"
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<string> vs;
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;
const int DIV = 2e9+7;

int main() {
    int h, w;
    cin >> h >> w;
    vs grid(h);
    rep(i, h) cin >> grid[i];
    vi skip_row, skip_column;
    bool is_skip;
    rep(row, h) {
        is_skip = true;
        rep(column, w) {
            if (grid[row][column] == '#') {
                is_skip = false; break;
            }
        }
        if (is_skip) skip_row.pb(row);
    }
    rep(column, w) {
        is_skip = true;
        rep(row, h) {
            if (grid[row][column] == '#') {
                is_skip = false; break;
            }
        }
        if (is_skip) skip_column.pb(column);
    }
    rep(row, h) {
        auto it = find(all(skip_row), row);
        if (it != skip_row.end()) continue;
        rep(column, w) {
            auto it = find(all(skip_column), column);
            if (it != skip_column.end()) continue;
            cout << grid[row][column];
        }
        cout << endl;
    }
}