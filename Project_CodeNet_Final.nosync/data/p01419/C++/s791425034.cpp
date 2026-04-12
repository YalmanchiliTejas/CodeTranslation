/*
 * C.cpp
 *
 *  Created on: Oct 9, 2012
 *      Author: carber
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#include <vector>
typedef long long LL;

const int maxr = 66;
const int maxm = 2048;
char g[maxr][maxr];
int last[maxr][maxr], sign[maxr][maxr];
int on[maxr][maxr], off[maxr][maxr];
int gc[maxr][maxr], wx[maxm], wy[maxm];
int R, C, M;
vector<vector<int> > ret;

bool input() {
    if (3 != scanf("%d %d %d", &R, &C, &M)) return false;
    for (int i = 0; i < R; ++i) {
        scanf("%s", g[i]);
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            scanf("%d", &gc[i][j]);
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            scanf("%d", &on[i][j]);
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            scanf("%d", &off[i][j]);
        }
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &wx[i], &wy[i]);
    }
    return true;
}

const int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
int Q[maxr * maxr], st, ed, pre[maxr * maxr];

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < R && y < C && g[x][y] != '#';
}

void bfs(int s, int e, int idx) {
    st = ed = 0; Q[ed++] = s;
    sign[s/C][s%C] = idx, pre[s] = s;
    while (st < ed) {
        if (Q[st] == e) {
            vector<int> tmp;
            int cs = pre[e];
            while (cs != s) {
                tmp.push_back(cs);
                cs = pre[cs];
            }
            tmp.push_back(cs);
            reverse(tmp.begin(), tmp.end());
            ret.push_back(tmp);
            return;
        }
        int x = Q[st] / C, y = Q[st++] % C;
        for (int k = 0; k < 4; ++k) {
            int tx = x + dir[k][0];
            int ty = y + dir[k][1];
            if (check(tx, ty) && sign[tx][ty] != idx) {
                sign[tx][ty] = idx;
                Q[ed++] = tx * C + ty;
                pre[Q[ed - 1]] = Q[st-1];
            }
        }
    }
}

void solved(int nT) {
    input();
        memset(last, -1, sizeof(last));
        memset(sign, -1, sizeof(sign));
        ret.clear();
        for (int i = 1; i < M; ++i) {
            bfs(wx[i-1] * C + wy[i-1], wx[i] * C + wy[i], i - 1);
        }
        ret.back().push_back(wx[M - 1] * C + wy[M-1]);

        int cost = 0, use = 0;

        for (int t = 0; t < (int)ret.size(); ++t) {
            for (int j = 0; j < (int)ret[t].size(); ++j) {
                int x = ret[t][j] / C, y = ret[t][j] % C;
                ++use;
                if (last[x][y] == -1) {
                    cost += on[x][y] + off[x][y];
                    last[x][y] = use;
                } else {
                    cost += min((use - last[x][y]) * gc[x][y], on[x][y] + off[x][y]);
                    last[x][y] = use;
                }
            }
        }
        printf("%d\n", cost);
    //}
}

int main() {
    int T = 1;
    for (int nT = 1; nT <= T; ++nT) {
        solved(nT);
    }
    return 0;
}