#include<bits/stdc++.h>
using namespace std;

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int H, W;
int a[10][10];

int main() {
    int cnt = 0;
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++)
        {
            if(s[j] == '#') {
                a[i][j] = 1;
                cnt++;
            }
            else a[i][j] = 0;
        }
    }

    vector<vector<int>> dist(10, vector<int>(10, -1));
    queue<pair<int, int>> que;
    dist[0][0] = 0;
    que.push(make_pair(0, 0));

    while (!que.empty())
    {
        int x, y;
        tie(y, x) = que.front();
        que.pop();

        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= W || ny >= H) continue;
            if(dist[ny][nx] != -1) continue;
            if(a[ny][nx] = 0) continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.push(make_pair(ny, nx));
        }
    }

    if(dist[H-1][W-1] == -1) cout << "Impossible" << endl;
    else if(cnt != dist[H-1][W-1] + 1) cout << "Impossible" << endl;
    else cout << "Possible" << endl;
}