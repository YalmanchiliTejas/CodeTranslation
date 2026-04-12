#include "bits/stdc++.h"
using namespace std;
typedef long long li;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li n;
    cin >> n;
    vector<li> xs(n), ys(n);
    vector<pair<li, li>> xys;

    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
        if (ys[i] < xs[i]) {
            swap(xs[i], ys[i]);
        }
        xys.emplace_back(xs[i], ys[i]);
    }
    sort(xys.begin(), xys.end());

    li x_min = *min_element(xs.begin(), xs.end());
    li x_max = *max_element(xs.begin(), xs.end());
    li y_min = *min_element(ys.begin(), ys.end());
    li y_max = *max_element(ys.begin(), ys.end());

    li ans = (x_max - x_min) * (y_max - y_min);

    multiset<li> x_bag(xs.begin(), xs.end());

    for (auto xy  : xys) {
        const li x = xy.first;
        const li y = xy.second;

        x_bag.erase(x_bag.lower_bound(x));
        x_bag.insert(y);
        ans = min(ans, (*x_bag.rbegin() - *x_bag.begin()) * (y_max - x_min));
    }
    cout << ans << endl;
    return 0;
}