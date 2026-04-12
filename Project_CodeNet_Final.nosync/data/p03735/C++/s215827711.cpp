#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using LL = long long;

LL solve(int N, vector<pair<LL, LL>> &xys);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<LL, LL>> xys(N);
    for (auto & xy : xys){
        cin >> xy.first >> xy.second;
        if (xy.first > xy.second) swap(xy.first, xy.second);
    }
    cout << solve(N, xys) << endl;
    return 0;
}

LL solve(int N, vector<pair<LL, LL>> &xys){
    // xmin = Rmin, ymax = Bmax となるケース
    // Rmax = xmax, Bmin = ymin とすればよい。
    LL xmin = 2e9;
    LL ymin = 2e9;
    LL xmax = -2e9;
    LL ymax = -2e9;
    LL xmin_rev_min = 2e9;
    LL xmin_rev_max = -2e9;
    LL ymax_rev_min = 2e9;
    LL ymax_rev_max = -2e9;
    vector<pair<int, LL>> ymax_idx_val;
    for (int i = 0; i != N; ++i){
        auto x = xys[i].first;
        auto y = xys[i].second;
        if (x == xmin){
            xmin_rev_min = min(xmin_rev_min, y);
            xmin_rev_max = max(xmin_rev_max, y);
        }
        if (x < xmin){
            xmin = x;
            xmin_rev_min = y;
            xmin_rev_max = y;
        }
        xmax = max(xmax, x);
        ymin = min(ymin, y);
        if (y == ymax){
            ymax_rev_min = min(ymax_rev_min, x);
            ymax_rev_max = max(ymax_rev_max, x);
        }
        if (y > ymax){
            ymax = y;
            ymax_rev_min = x;
            ymax_rev_max = x;
        }
    }
    LL ans1 = (xmax - xmin) * (ymax - ymin);

    // xmin = Rmin, ymax = Rmax となるケース
    LL Bmin = min(ymax_rev_min, xmin_rev_min);
    LL Bmax = max(ymax_rev_max, xmin_rev_max);
    sort(xys.begin(), xys.end());
    Bmax = max(Bmax, xys.back().first);
    LL record = Bmax - xys[0].first;
    for (int i = 1; i != N; ++i){
        Bmax = max(Bmax, xys[i - 1].second);
        Bmin = min(Bmin, xys[i - 1].second);
        record = min(record, Bmax - min(Bmin, xys[i].first));
    }
    LL ans2 = (ymax - xmin) * record;

    return min(ans1, ans2);

}
