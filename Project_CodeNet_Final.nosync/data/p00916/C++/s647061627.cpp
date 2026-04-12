#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl

const int MAX_N = 50;
// x, y
int field[2 * (2 * MAX_N) + 1][2 * (2 * MAX_N) + 1];

int X, Y;

typedef pair<int, int> P;
void dfs(int x, int y) {
    queue<P> Q;
    Q.push(P(x, y));
    while(!Q.empty()) {
        P p = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int dx[4] = { 1, 0, -1, 0 };
            int dy[4] = { 0, 1, 0, -1 };
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(0 <= nx && nx < X && 0 <= ny && ny < Y && field[nx][ny] == 0) {
                field[nx][ny] = 1;
                Q.push(P(nx, ny));
            }
        }
    }
}

void show() {
#if 0
   cerr << '-' << endl;
   for(int i = Y - 1; i >= 0; i--) {
       for(int j = 0; j < X; j++) {
           cerr << field[j][i];
       }
       cerr << '|' << endl;
   }
   cerr << '-' << endl;
#endif
}

int main() {
    while(true) {
        int N; cin >> N;
        if(N == 0) break;
        vector<int> x1(N), y1(N), x2(N), y2(N);
        vector<int> xs;
        vector<int> ys;
        for(int i = 0; i < N; i++) {
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
            xs.push_back(x1[i]);
            xs.push_back(x2[i]);
            ys.push_back(y1[i]);
            ys.push_back(y2[i]);
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        for(int i = 0; i < N; i++) {
            x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
            y1[i] = find(ys.begin(), ys.end(), y1[i]) - ys.begin();
            x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
            y2[i] = find(ys.begin(), ys.end(), y2[i]) - ys.begin();
        }
        memset(field, 0, sizeof(field));
        for(int i = 0; i < N; i++) {
            for(int x = 2 * x1[i]; x <= 2 * x2[i]; x++) {
                field[x + 1][2 * y1[i] + 1] = 1;
                field[x + 1][2 * y2[i] + 1] = 1;
            }
            for(int y = 2 * y1[i]; y >= 2 * y2[i]; y--) {
                field[2 * x1[i] + 1][y + 1] = 1;
                field[2 * x2[i] + 1][y + 1] = 1;
            }
        }
        X = 2 * (int)xs.size() + 1;
        Y = 2 * (int)ys.size() + 1;
        show();
        int ans = 0;
        for(int x = 0; x < X; x++) {
            for(int y = 0; y < Y; y++) {
                if(field[x][y] == 0) {
                    ans++;
                    field[x][y] = 1;
                    dfs(x, y);
                    show();
                }
            }
        }
        cout << ans << endl;
    }
}