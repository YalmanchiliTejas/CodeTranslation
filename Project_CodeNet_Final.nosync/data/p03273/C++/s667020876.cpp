#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1LL << 60;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-6;
using pii = std::pair<int, int>;
using pLL = std::pair<long long, long long>;
using ll = long long;
#define SORT(v) std::sort(v.begin(), v.end())
#define rSORT(v) std::sort(v.begin(), v.end(),std::greater<int>())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
        }
    }
    vector<bool> col(W, false), row(H, false);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (a[i][j] == '#') col[j] = true, row[i] = true;
        }
    }
    for (int i = 0; i < H; ++i) {
        if (row[i]) {
            for (int j = 0; j < W; ++j) {
                if (col[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}