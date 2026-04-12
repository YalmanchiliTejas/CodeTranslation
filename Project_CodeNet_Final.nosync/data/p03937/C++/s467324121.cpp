#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool dfs(int x, int y, vector<string> const& v, vector<vector<bool>>& used) {
    if(y == v.size()-1 && x == v[0].size()-1) {
        for(int i=0; i<v.size(); ++i) {
            for(int j=0; j<v[0].size(); ++j) {
                if(v[i][j] == '#' && !used[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    int dx[2] = {0, 1}, dy[2] = {1, 0};
    bool ret = false;
    for(int i=0; i<2; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < v[0].size() && ny < v.size() && v[ny][nx] == '#') {
            used[ny][nx] = true;
            ret |= dfs(nx, ny, v, used);
            used[ny][nx] = false;
        }
    }
    return ret;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for(int i=0; i<h; ++i) {
        cin >> v[i];
    }
    vector<vector<bool>> used(h, vector<bool>(w, false));
    used[0][0] = true;
    cout << (dfs(0, 0, v, used) ? "Possible" : "Impossible") << endl;
}
