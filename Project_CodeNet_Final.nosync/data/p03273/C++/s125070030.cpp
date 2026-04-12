#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int main() {
    int H, W;
    string A[100];
    cin >> H >> W;
    REP(i, H) cin >> A[i];

    vector<int> hv, wv;
    REP(i, H) REP(j, W) if (A[i][j] == '#') {
        hv.push_back(i);
        break;
    }
    REP(j, W) REP(i, H) if (A[i][j] == '#') {
        wv.push_back(j);
        break;
    }
    for (int i : hv) { for (int j : wv) cout << A[i][j]; cout << endl; }
    return 0;
}