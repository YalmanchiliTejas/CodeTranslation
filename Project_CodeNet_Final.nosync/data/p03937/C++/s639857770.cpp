#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<bool>> seen(h, vector<bool>(w, false));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    seen[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        seen[y][x] = true;

        int dir_cnt = 0;
        rep(dir, 4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(0>ny || ny>=h || 0>nx || nx>=w) continue;

            if(s[ny][nx] == '#' && !seen[ny][nx]){
                if(dir > 1) ++dir_cnt;
                q.push(make_pair(nx, ny));
                ++dir_cnt;
            }
        }

        if(dir_cnt > 1) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    if(seen[h-1][w-1])cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}