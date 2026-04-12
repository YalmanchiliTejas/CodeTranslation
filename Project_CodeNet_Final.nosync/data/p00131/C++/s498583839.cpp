#include <iostream>
#include <cstring>

using namespace std;

const int dx[] = {0, -1, 0, 1, 0};
const int dy[] = {-1, 0, 0, 0, 1};

int n;
int default_state[10][10];
int state[10][10];
int ans[10][10];

void pass(int y, int x) {
    for (int i=0; i<5; ++i) {
        if (0 <= y + dy[i] && y + dy[i] < 10 && 0 <= x + dx[i] && x + dx[i] < 10) {
            state[y + dy[i]][x + dx[i]] = 1 - state[y + dy[i]][x + dx[i]];
        }
    }
    ans[y][x] = 1 - ans[y][x];
}

void solve() {
    for (int bt=0; bt<(1<<10); ++bt) {
        memcpy(state, default_state, sizeof(default_state));
        memset(ans, 0, sizeof(ans));
        for (int j=0; j<10; ++j) {
            if ((bt>>j) & 1) {
                pass(0, j);
            }
        }
        for (int i=1; i<10; ++i) {
            for (int j=0; j<10; ++j) {
                if (state[i-1][j] == 1) {
                    pass(i, j);
                }
            }
        }
        bool ok = true;
        for (int i=0; i<10; ++i) {
            for (int j=0; j<10; ++j) {
                if (state[i][j] == 1) ok = false;
            }
        }
        if (ok) return ;
    }
}

int main() {
    cin >> n;
    while (n --) {
        for (int i=0; i<10; ++i) {
            for (int j=0; j<10; ++j) {
                cin >> default_state[i][j];
            }
        }
        solve();
        for (int i=0; i<10; ++i) {
            for (int j=0; j<10; ++j) {
                cout << (j == 0 ? "" : " ") << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}