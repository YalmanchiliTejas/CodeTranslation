#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        using Line = tuple<int, int, int>;
        // list of vertical lines
        // x, bottom y, top y
        vector<Line> vl;
        // list of horizontal lines
        // y, left x, right x
        vector<Line> hl;
        // x coordinates
        vector<int> xs;
        // y coordinates
        vector<int> ys;
        for (int i = 0; i < n; ++i) {
            int l, t, r, b;
            cin >> l >> t >> r >> b;
            xs.emplace_back(l);
            xs.emplace_back(r);
            ys.emplace_back(t);
            ys.emplace_back(b);
            vl.emplace_back(l, b, t);
            vl.emplace_back(r, b, t);
            hl.emplace_back(t, l, r);
            hl.emplace_back(b, l, r);
        }
        xs.emplace_back(-1);
        xs.emplace_back(1'000'001);
        ys.emplace_back(1'000'001);
        ys.emplace_back(-1);
        vl.emplace_back(-1, -1, 1'000'001);
        vl.emplace_back(1'000'001, -1, 1'000'001);
        hl.emplace_back(1'000'001, -1, 1'000'001);
        hl.emplace_back(-1, -1, 1'000'001);

        // make unique
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
        sort(begin(ys), end(ys));
        ys.erase(unique(begin(ys), end(ys)), end(ys));

        // walls along with x-axis
        auto makeWalls = [](const vector<int>& axis, const vector<int>& ranges,
                            const vector<Line>& lines) {
            vector<vector<bool>> walls(axis.size(),
                                       vector<bool>(ranges.size() - 1, false));
            for (size_t i = 0; i < walls.size(); ++i) {
                const auto a = axis[i];
                for (size_t j = 0; j < walls[i].size(); ++j) {
                    const auto b1 = ranges[j];
                    const auto b2 = ranges[j + 1];
                    for (auto&& l : lines) {
                        int ax, ss, bb;
                        tie(ax, ss, bb) = l;
                        if (ax != a) {
                            continue;
                        }
                        if ((ss <= b1 && b1 <= bb) && (ss <= b2 && b2 <= bb)) {
                            walls[i][j] = true;
                            break;
                        }
                    }
                }
            }
            return walls;
        };
        const auto xWalls = makeWalls(xs, ys, vl);
        const auto yWalls = makeWalls(ys, xs, hl);

        constexpr int NOT_SEARCHED = -1;
        vector<vector<int>> v(xs.size() - 1,
                              vector<int>(ys.size() - 1, NOT_SEARCHED));
        int color = 1;
        queue<pair<int, int>> searchQueue;
        queue<pair<int, int>> keepQueue;
        searchQueue.emplace(0, 0);
        while (true) {
            if (searchQueue.empty()) {
                if (keepQueue.empty()) {
                    break;
                }
                searchQueue.emplace(keepQueue.front());
                keepQueue.pop();
                color += 1;
            }
            int i, j;
            tie(i, j) = searchQueue.front();
            searchQueue.pop();
            if (v[i][j] == NOT_SEARCHED) {
                v[i][j] = color;
            }
            else {
                continue;
            }
            // left
            if (i != 0) {
                if (xWalls[i][j]) {
                    keepQueue.emplace(i - 1, j);
                }
                else {
                    searchQueue.emplace(i - 1, j);
                }
            }
            // right
            if (i != v.size() - 1) {
                if (xWalls[i + 1][j]) {
                    keepQueue.emplace(i + 1, j);
                }
                else {
                    searchQueue.emplace(i + 1, j);
                }
            }
            // bottom
            if (j != 0) {
                if (yWalls[j][i]) {
                    keepQueue.emplace(i, j - 1);
                }
                else {
                    searchQueue.emplace(i, j - 1);
                }
            }
            // up
            if (j != v[i].size() - 1) {
                if (yWalls[j + 1][i]) {
                    keepQueue.emplace(i, j + 1);
                }
                else {
                    searchQueue.emplace(i, j + 1);
                }
            }
        }

        // count number of colors
        unordered_set<int> s;
        for (auto&& i : v) {
            for (auto&& j : i) {
                s.emplace(j);
            }
        }

        cout << s.size() << endl;
    }
}
