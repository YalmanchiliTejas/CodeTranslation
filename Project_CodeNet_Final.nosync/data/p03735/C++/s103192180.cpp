#include"bits/stdc++.h"
using namespace std;

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> x(N), y(N);
    for (int64_t i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    int64_t min_value = min(*min_element(x.begin(), x.end()), *min_element(y.begin(), y.end()));
    int64_t max_value = max(*max_element(x.begin(), x.end()), *max_element(y.begin(), y.end()));

    int64_t R_min = min_value;

    int64_t ans = LLONG_MAX;
    {
        //B_max = max_valueの場合
        int64_t B_max = max_value;
        int64_t R_max = min_value, B_min = max_value;
        for (int64_t i = 0; i < N; i++) {
            R_max = max(R_max, min(x[i], y[i]));
            B_min = min(B_min, max(x[i], y[i]));
        }
        ans = min(ans, (R_max - R_min) * (B_max - B_min));
    }
    {
        //R_max = max_valueの場合
        int64_t R_max = max_value;
        vector<pair<int64_t, int64_t>> xy;
        for (int64_t i = 0; i < N; i++) {
            xy.emplace_back(min(x[i], y[i]), max(x[i], y[i]));
        }
        sort(xy.begin(), xy.end(), [](pair<int64_t, int64_t>& lhs, pair<int64_t, int64_t>& rhs){
            return lhs.first < rhs.first;
        });

        multiset<int64_t> blues;
        blues.insert(xy[0].second);
        for (int64_t i = 1; i < N; i++) {
            blues.insert(xy[i].first);
        }
        int64_t B_width = *(--blues.end()) - *blues.begin();
        for (int64_t i = 1; i < N; i++) {
            blues.erase(blues.find(xy[i].first));
            blues.insert(xy[i].second);
            B_width = min(B_width, *(--blues.end()) - *blues.begin());
        }
        ans = min(ans, (R_max - R_min) * B_width);
    }

    cout << ans << endl;
}