#include <bits/stdc++.h>
using namespace std;

bool v[10][10];
int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};
string s[10];
int h, w;

bool dfs(int x,int y)
{
    v[y][x] = true;

    // for(int i=0;i<h;i++){for(int j=0;j<w;j++)cerr<<v[i][j];cerr<<endl;}cerr<<endl;

    if (x == w - 1 && y == h - 1) return true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i],
            ny = y + dy[i];
        if (true
            && nx >= 0
            && nx < w
            && ny >= 0
            && ny < h
            && s[ny][nx] == '#'
        ) {
            // cerr << y << " " << x << " " << dy[i] << " " << dx[i] << " " << v[ny][nx] << endl;
            if ((dx[i] < 0 || dy[i] < 0) && !v[ny][nx]) return false;
            else if (v[ny][nx]) continue;
            else return dfs(nx, ny);
        }
    }
    return false;
}
int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> s[i];

    bool f = dfs(0, 0);

    int c = 0, cc = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            c += s[i][j] == '#';
            cc += v[i][j];
        }
    }

    cout << (f && c == cc ? "Possible" : "Impossible") << endl;

    return 0;
}
