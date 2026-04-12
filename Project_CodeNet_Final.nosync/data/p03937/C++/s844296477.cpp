#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
using point = pair<int, int>;
vector<int> x_ = {0, 1};
vector<int> y_ = {1, 0};
int main() {
    int H, W;
    cin >> H >> W;
    vector<string>vec(H);
    vector<vector<int>> seen(H, vector<int>(W, -1));
    for (int i=0; i < H; i++) {
        cin >> vec.at(i);
    }

    queue<point> que;
    que.push(point(0, 0));
    while (!que.empty()) {
        point p = que.front();
        que.pop();
        if (vec[p.first][p.second] == '#') {
            seen[p.first][p.second] = 1;
        } else {
            continue;
        }

        bool souhoukou = false;
        int count = 0;
        for (int i=0; i<2; i++) {
            int new_y = p.first + y_[i];
            int new_x = p.second + x_[i];
            if (new_y < 0 || new_y >= H) continue;
            if (new_x < 0 || new_x >= W) continue;
            if (vec[new_y][new_x] == '#') ++count;
            point new_p = point(new_y, new_x);
            que.push(new_p);
        }

        if (count == 2) {
            seen[p.first][p.second] = 0;
        }
    }

    bool possible = true;
    for (int i=0; i < H; i++) {
        for (int j=0; j < W; j++) {
            if (vec[i][j] == '#' && seen[i][j] != 1) {
                possible = false;
            }
        }
    }

    if (possible) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}