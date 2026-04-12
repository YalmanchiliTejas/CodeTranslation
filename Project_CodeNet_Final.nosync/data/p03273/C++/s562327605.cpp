#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const ll INF = 1e18;
const int MAX = 1e6;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

// struct edge {int to, cost;}; // 辺
// vector<edge> graph[MAX]; // 隣接リスト
// bool visited[MAX]; // 訪問状況


int main() {
    // input
    int h, w;
    cin >> h >> w;
    char a[h][w];
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }
    // solve
    bool skip_i[h];
    bool skip_j[w];
    memset(skip_i, 1, sizeof(skip_i));
    memset(skip_j, 1, sizeof(skip_j));
    rep(i, h) {
        rep(j, w) {
            if (a[i][j] == '#') {
                skip_i[i] = false;
                skip_j[j] = false;
            }
        }
    }
    // output
    rep(i, h) {
        if (skip_i[i]) continue;
        rep(j, w) {
            if (skip_j[j]) continue;
            cout << a[i][j];
        }
        printf("\n");
    }
}