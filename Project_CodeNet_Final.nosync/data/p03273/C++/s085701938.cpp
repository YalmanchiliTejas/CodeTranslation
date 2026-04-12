#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()

struct P {
    bool r;
    bool c;
};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> m;
    vector<vector<P>> p;
    m.resize(H);
    p.resize(H);
    REP(i, H) {
        m[i].resize(W);
        p[i].resize(W);
    }
    REP(i, H) {
        REP(j, W) {
            cin >> m[i][j];
        }
    }
    REP(i, H) {
        REP(j, W) {
            if(m[i][j] == '#') {
                REP(r, H) {
                    p[r][j].r = true;
                }
                REP(c, W) {
                    p[i][c].c = true;
                }
            }
        }
    }
    REP(i, H) {
        bool x = false;
        REP(j, W) {
            if(p[i][j].r && p[i][j].c) {
                cout << m[i][j];
                x = true;
            }
        }
        if(x) {
            cout << endl;
        }
    }
    return 0;
}
