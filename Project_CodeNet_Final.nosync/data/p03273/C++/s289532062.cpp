#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> a[i][j];
    vector<vector<int>> ng(H, vector<int>(W));
    rep(i, W) {
        int cnt = 0;
        rep(j, H) {
            if(a[j][i] == '.')
                cnt++;
        }
        if(cnt == H) {
            rep(j, H) { ng[j][i] = 1; }
        }
    }

    rep(i, H) {
        int cnt = 0;
        rep(j, W) {
            if(a[i][j] == '.')
                cnt++;
        }
        if(cnt == W) {
            rep(j, W) { ng[i][j] = 1; }
        }
    }
    rep(i, H) {
        int ok = 0;
        rep(j, W) {
            if(!ng[i][j]) {
                cout << a[i][j];
                ok = 1;
            }
        }
        if(ok)
            cout << endl;
    }
    return 0;
}