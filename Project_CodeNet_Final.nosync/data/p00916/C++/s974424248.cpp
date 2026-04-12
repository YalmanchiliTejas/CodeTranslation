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

        // {x,y}-axis, {bottom, left}, {top, right}
        using Line = tuple<int, int, int>;
        vector<Line> vl;
        vector<Line> hl;
        // count number of ranges
        vector<int> xs;
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
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
        sort(begin(ys), end(ys));
        ys.erase(unique(begin(ys), end(ys)), end(ys));

        // walls along with x-axis
        vector<vector<bool>> xWalls(xs.size(),
                                    vector<bool>(ys.size() - 1, false));
        for (size_t i = 0; i < xWalls.size(); ++i) {
            const auto x = xs[i];
            for (size_t j = 0; j < xWalls[i].size(); ++j) {
                const auto y1 = ys[j];
                const auto y2 = ys[j + 1];
                vector<Line> t;
                copy_if(begin(vl), end(vl), back_inserter(t),
                        [x](const Line& l) { return get<0>(l) == x; });
                for (auto&& l : t) {
                    auto lb = get<1>(l);
                    auto lt = get<2>(l);
                    if ((lb <= y1 && y1 <= lt) && (lb <= y2 && y2 <= lt)) {
                        xWalls[i][j] = true;
                        break;
                    }
                }
            }
        }

        // walls along with y-axis
        vector<vector<bool>> yWalls(ys.size(),
                                    vector<bool>(xs.size() - 1, false));
        for (size_t i = 0; i < yWalls.size(); ++i) {
            const auto y = ys[i];
            for (size_t j = 0; j < yWalls[i].size(); ++j) {
                const auto x1 = xs[j];
                const auto x2 = xs[j + 1];
                vector<Line> t;
                copy_if(begin(hl), end(hl), back_inserter(t),
                        [y](const Line& l) { return get<0>(l) == y; });
                for (auto&& l : t) {
                    auto ll = get<1>(l);
                    auto lr = get<2>(l);
                    if ((ll <= x1 && x1 <= lr) && (ll <= x2 && x2 <= lr)) {
                        yWalls[i][j] = true;
                        break;
                    }
                }
            }
        }

        constexpr int NOT_SEARCHED = -1;
        vector<vector<int>> v(xs.size() - 1,
                              vector<int>(ys.size() - 1, NOT_SEARCHED));

        int count = 1;
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
                count += 1;
            }
            int i, j;
            tie(i, j) = searchQueue.front();
            searchQueue.pop();
            if (v[i][j] == NOT_SEARCHED) {
                v[i][j] = count;
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

        unordered_set<int> s;
        for (auto&& i : v) {
            for (auto&& j : i) {
                s.emplace(j);
            }
        }

        cout << s.size() << endl;
    }
}
