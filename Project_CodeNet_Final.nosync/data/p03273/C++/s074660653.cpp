#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(w);
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        if (s.find("#") != string::npos) {
            for (int j = 0; j < w; j++) {
                grid[j].push_back(s[j]);
            }
        }
    }
    vector<vector<char>> ans(grid[0].size());
    for (int x = 0; x < w; x++) {
        if (find(grid[x].begin(), grid[x].end(), '#') != grid[x].end()) {
            for (int y = 0; y < grid[x].size(); y++) {
                ans[y].push_back(grid[x][y]);
            }
        }
    }

    for (int y = 0; y < ans.size(); y++) {
        for (auto&& e : ans[y]) {
            cout << e;
        }
        cout << endl;
    }
}
