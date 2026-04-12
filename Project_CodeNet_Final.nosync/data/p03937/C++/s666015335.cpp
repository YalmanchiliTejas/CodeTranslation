#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid;
    string s;
    int cnt = 0;
    for(int i = 0; i < h; i++) {
        cin >> s;
        grid.push_back(s);
        for(int j = 0; j < w; j++) {
            if (s[j] == '#')
                cnt += 1;
        }
    }
    if (cnt != h+w-1) {
        cout << "Impossible" << endl;
    } else {
        auto dfs = [&] (auto& self, int r, int c) -> void {
            if (r < 0 || r >= h || c < 0 || c >= w || grid[r][c] == '.')
                return;
            grid[r][c] = '.';
            self(self, r, c-1);
            self(self, r, c+1);
            self(self, r-1, c);
            self(self, r+1, c);
            
        };
        dfs(dfs, 0, 0);
        if (grid[h-1][w-1] == '.')
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }
    return 0;
}
