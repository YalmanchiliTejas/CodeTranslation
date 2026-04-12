#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
// #include <bits/stdc++.h>

using namespace std;
typedef long long li;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    li n;
    cin >> n;

    multiset<li> last_points;
    for (int i = 0; i < n; ++i) {
        li x;
        cin >> x;
        auto p = last_points.lower_bound(x);
        if (p == last_points.begin()) {
            last_points.insert(x);
        } else {
            p--;
            last_points.erase(p);
            last_points.insert(x);
        }
    }

    cout << last_points.size() << endl;
    return 0;
}
