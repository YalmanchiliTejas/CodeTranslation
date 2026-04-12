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
    vector<vector<char>> B(H, vector<char>(W));
    int cnt = 0;
    rep(i, H) rep(j, W) {
        cin >> B[i][j];
        if(B[i][j] == '#')
            cnt++;
    }
    if(cnt > H + W - 1) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
    }
    return 0;
}