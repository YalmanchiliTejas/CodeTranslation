#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 4LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}


#define int ll

unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int grid[100][100];
int cost[2][100][100];
int back_dist[100][100];
int ans = 0;
int dist[100][100];

int h, w, m;

int dfs(pair<int, int> now, pair<int, int> back, pair<int, int> target) {
    int reflect = 0;
    if (now == target) {
        reflect = 1;
    }
    else {
        int dx[4] = { 1,-1,0,0 };
        REP(t, 4) {
            int x = now.first + dx[t];
            int y = now.second + dx[3 - t];
            if (x >= 0 && x < h && y >= 0 && y < w) {
                if (mp(x, y) == back) continue;
                if (grid[x][y] == 1) continue;
                dist[x][y] = dist[now.first][now.second] + 1;
                if (dfs(mp(x, y), now, target) == 1) {
                    reflect = 1;
                    break;
                }
            }
        }
    }
    if (reflect == 1) {
        if (back_dist[now.first][now.second] == -1e9) {
            ans += cost[1][now.first][now.second];
        }else
        ans += min(cost[1][now.first][now.second], cost[0][now.first][now.second] * (dist[now.first][now.second] - back_dist[now.first][now.second]));
        back_dist[now.first][now.second] = dist[now.first][now.second];
        return 1;
    }
    return 0;
}

void solve() {
    cin >> h >> w >> m;
    REP(i, h) {
        string s;
        cin >> s;
        REP(q, w) {
            if (s[q] == '#') {
                grid[i][q] = 1;
            }
        }
    }
    REP(i, 3) {
        REP(q, h) {
            REP(j, w) {
                int hogge;
                cin >> hogge;
                cost[min(1LL, i)][q][j] += hogge;
            }
        }
    }
    REP(i, h) {
        REP(q, w) {
            back_dist[i][q] = -1e9;
        }
    }
    pair<int, int> now;
    cin >> now.first >> now.second;
    REP(i, m-1) {
        pair<int, int> target;
        cin >> target.first >> target.second;
        dfs(now, mp(-1,-1), target);
        now = target;
    }
    cout << ans << endl;
}

#undef int
int main() {
    init();
    solve();
}

