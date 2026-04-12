#include <bits/stdc++.h>

using namespace std;

namespace {

    typedef long long Long;

    struct Point {
        int y, x;
        Point() {}
        Point(int y, int x) : y(y), x(x) {}
    };
    ostream& operator<<(ostream& os, const Point& p) {
        return os << "Point(" << p.y << "," << p.x << ")";
    }

    int R, C, M;
    vector<string> F;
    vector< vector<Long> > cost, onCost, offCost;
    vector<Point> V;
    void input() {
        cin >> R >> C >> M;
        F.clear(); F.resize(R);
        for (int i = 0; i < R; i++) cin >> F[i];
        cost.clear(); cost.resize(R, vector<Long>(C, 0));
        onCost.clear(); onCost.resize(R, vector<Long>(C, 0));
        offCost.clear(); offCost.resize(R, vector<Long>(C, 0));
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> cost[i][j];
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> onCost[i][j];
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> offCost[i][j];
        V.clear(); V.resize(M);
        for (int i = 0; i < M; i++) {
            int y, x; cin >> y >> x;
            V[i] = Point(y, x);
        }
    }

    struct S {
        int y, x;
        int py, px;
        S() {}
        S(int y, int x, int py, int px) : y(y), x(x), py(py), px(px) {}
    };

    vector< vector< queue<int> > > X;
    const int INF = 1<<28;

    const int dy[] = {-1, 0, 1, 0};
    const int dx[] = {0, 1, 0, -1};

    void bfs(int sy, int sx, int gy, int gx, int& t) {
        queue<S> Q;
        vector< vector<int> > D(R, vector<int>(C, INF));
        vector< vector<Point> > P(R, vector<Point>(C));
        Q.push(S(sy, sx, -1, -1));
        D[sy][sx] = 0;
        while (!Q.empty()) {
            S c = Q.front(); Q.pop();
            int y = c.y, x = c.x;
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i],
                    nx = x + dx[i];
                if (ny < 0 || ny >= R) continue;
                if (nx < 0 || nx >= C) continue;
                if (F[ny][nx] == '#') continue;
                if (D[ny][nx] <= D[y][x] + 1) continue;
                D[ny][nx] = D[y][x] + 1;
                P[ny][nx] = Point(y, x);
                Q.push(S(ny, nx, y, x));
            }
        }
        int cy = gy, cx = gx;
        while (cy != sy || cx != sx) {
            X[cy][cx].push(D[cy][cx] + t);
            int ny = P[cy][cx].y,
                nx = P[cy][cx].x;
            cy = ny;
            cx = nx;
        }
        t += D[gy][gx];
    }

    void solve() {
        X.clear(); X.resize(R, vector< queue<int> >(C));
        int y = V[0].y, x = V[0].x;
        X[y][x].push(0);
        int t = 0;
        for (int i = 1; i < M; i++) {
            int gy = V[i].y, gx = V[i].x;
            bfs(y, x, gy, gx, t);
            y = gy; x = gx;
        }
        Long ans = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                queue<int>& Q = X[i][j];
                while (!Q.empty()) {
                    Long s = Q.front(); Q.pop();
                    if (Q.empty()) {
                        ans += offCost[i][j] + onCost[i][j];
                    } else {
                        Long t = Q.front();
                        ans += min(cost[i][j] * (t - s), offCost[i][j] + onCost[i][j]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}

int main() {
    input(); solve();
    return 0;
}