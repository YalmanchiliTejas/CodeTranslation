#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    char C[h][w];
    int Dist[h][w] = {};
    int sc = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> C[i][j];
            sc += (C[i][j] == '#');
            Dist[i][j] = 1e9;
        }
    }
    Dist[0][0] = 1;

    int dx[2] = {0, 1};
    int dy[2] = {1, 0};

    queue<pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;
        for(int i = 0; i < 2; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 or ny < 0 or nx >= h or ny >= w) continue;
            if(C[nx][ny] == '.') continue;
            if(Dist[nx][ny] > Dist[x][y] + 1){
                Dist[nx][ny] = Dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if(Dist[h - 1][w - 1] == -1 or sc - Dist[h - 1][w - 1] != 0) cout << "Impossible" << endl;
    else cout << "Possible" << endl;

    return 0;
}