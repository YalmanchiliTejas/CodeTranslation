#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <list>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iterator> 
#include <limits>

#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define ALL(a) (a).begin(),(a).end()
#define RALL(A) (a).rbegin(),(a).rend()
#define PB push_back
#define MP make_pair

#define dump(x) cerr << #x << " = " << (x) << endl;

using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

const int MAX_H = 10;
const int MAX_W = 10;
char maze[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W];
int H, W;
bool flg;

bool check() {
    REP(i, H) {
        REP(j, W) {
            if (maze[i][j] == '#' and visited[i][j] == false) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int h, int w) {
    //cout << h << " " << w << endl;
    if (flg) {
        return;
    }
    visited[h][w] = true;
    if (h == H - 1 and w == W - 1) {
        if (check()) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
        flg = true;
        return;
    }
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    REP(i, 2) {
        int nx = h + dx[i];
        int ny = w + dy[i];
        if (0 <= nx and nx < H and 0 <= ny and ny < W) {
            if (maze[nx][ny] == '#' and visited[nx][ny] == false) {
                dfs(nx, ny);
                visited[nx][ny] = false;
            }
        }
    }

}

int main(int argc, char const* argv[])
{
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> maze[i][j];
        }
    }
    dfs(0, 0);
    if (flg == false) {
        cout << "Impossible" << endl;
    }
    return 0;
}
