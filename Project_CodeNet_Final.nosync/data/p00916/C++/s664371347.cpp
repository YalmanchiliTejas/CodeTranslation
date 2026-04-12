#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

int field[350][350];
int dx[] = { 0, 1, 0,-1};
int dy[] = {-1, 0, 1, 0};

void dfs(int y, int x, int label) {
    if (x < 0 || x >= 350 || y < 0 || y >= 350) return;
    if (field[y][x] != -1) return;
    field[y][x] = label;
    for (int i=0; i<4; ++i) {
        dfs(y + dy[i], x + dx[i], label);
    }
}

int main() {
    int n;
    while (cin >> n, n) {
        vector<int> vx, vy;
        vector<int> ls, ts, rs, bs;

        for (int i=0; i<350; ++i) for (int j=0; j<350; ++j) field[i][j] = -1;

        for (int i=0; i<n; ++i) {
            int l,t,r,b;
            cin >> l >> t >> r >> b;
            ls.push_back(l);
            ts.push_back(t);
            rs.push_back(r);
            bs.push_back(b);

            for (int i=-1; i<=1; ++i) {
                vx.push_back(l + i);
                vx.push_back(r + i);
                vy.push_back(t + i);
                vy.push_back(b + i);
            }
        }

        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        map<int,int> convert_x, convert_y;
        for (int i=0; i<vx.size(); ++i) convert_x[vx[i]] = i;
        for (int i=0; i<vy.size(); ++i) convert_y[vy[i]] = i;

        // ??§?¨???§???
        for (int i=0; i<n; ++i) {
            ls[i] = convert_x[ ls[i] ];
            ts[i] = convert_y[ ts[i] ];
            rs[i] = convert_x[ rs[i] ];
            bs[i] = convert_y[ bs[i] ];
        }

        /*
        // debug
        for (int i=0; i<n; ++i) {
            printf("%3d %3d %3d %3d\n", ls[i], ts[i], rs[i], bs[i]);
        }
        cout << endl;
        */

        // ????????????????????????, -1?????????0?????????1??\?????§????????????
        for (int k=0; k<n; ++k) {
            // ?¨???¨????????????
            for (int i=ls[k]; i<=rs[k]; ++i) {
                field[ts[k]][i] = 0;
                field[bs[k]][i] = 0;
            }
            for (int i=bs[k]; i<=ts[k]; ++i) {
                field[i][ls[k]] = 0;
                field[i][rs[k]] = 0;
            }
        }
        /*
        // debug
        for (int i=0; i<50; ++i) {
            for (int j=0; j<50; ++j) {
                printf(" %2d", field[i][j]);
            }
            cout << endl;
        }
        cout << endl;
        */
        int label = 1;
        for (int i=0; i<350; ++i) {
            for (int j=0; j<350; ++j) if (field[i][j] == -1) {
                dfs(i,j,label);
                label++;
            }
        }

        /*
        // debug
        for (int i=0; i<50; ++i) {
            for (int j=0; j<50; ++j) {
                printf(" %2d", field[i][j]);
            }
            cout << endl;
        }
        cout << endl;
        */

        cout << label - 1 << endl;
    }
    return 0;
}