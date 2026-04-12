#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

const int S = 1000;
int sx[60], sy[60], tx[60], ty[60];
int board[S+10][S+10], used[S+10][S+10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    while(1) {
        memset(used, 0, sizeof(used));
        memset(board, 0, sizeof(board));
        int N; scanf("%d", &N);
        if(!N) break;

        map<int, int> mpx, mpy;
        for(int i=0; i<N; i++) {
            scanf("%d%d%d%d", &sx[i], &sy[i], &tx[i], &ty[i]);
            swap(sy[i], ty[i]);
            sx[i] *= 2, sy[i] *= 2, tx[i] *= 2, ty[i] *= 2;
            for(int k=-1; k<=1; k++) {
                int ssx = sx[i] + k, ssy = sy[i] + k;
                int ttx = tx[i] + k, tty = ty[i] + k;
                mpx[ssx]++; mpy[ssy]++;
                mpx[ttx]++; mpy[tty]++;
            }
        }

        int idx = 0, idy = 0;
        for(auto &x : mpx) {
            x.second = idx++;
        }
        for(auto &y : mpy) {
            y.second = idy++;
        }

        for(int i=0; i<N; i++) {
            int ux = mpx[sx[i]], uy = mpy[sy[i]];
            int vx = mpx[tx[i]], vy = mpy[ty[i]];
            for(int x=ux; x<=vx; x++) {
                board[x][uy] = board[x][vy] = 1;
            }
            for(int y=uy; y<=vy; y++) {
                board[ux][y] = board[vx][y] = 1;
            }
        }

        long long int ans = 0;
        for(int i=0; i<idx; i++) {
            for(int j=0; j<idy; j++) {
                if(used[i][j] || board[i][j] == 1) continue;
                ans++;
                used[i][j] = true;

                queue<pii> que;
                que.push(make_pair(i, j));

                while(que.size()) {
                    pii cur = que.front(); que.pop();
                    int x = cur.first, y = cur.second;
                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if(nx < 0 || nx >= idx || ny < 0 || ny >= idy) continue;
                        if(board[nx][ny] == 1 || used[nx][ny]) continue;
                        used[nx][ny] = true;
                        que.push(make_pair(nx, ny));
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
