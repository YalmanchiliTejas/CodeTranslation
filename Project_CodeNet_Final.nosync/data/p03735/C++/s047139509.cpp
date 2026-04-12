#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;

    pair<int, int> global_min{INT_MAX, -1},
                   global_max{INT_MIN, -1};
    vector<pair<int, int>> balls(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);

        balls[i] = {x,y};
        global_min = min(global_min, {x,i});
        global_max = max(global_max, {y,i});
    }

    long long ans = LLONG_MAX;

    // put the global min and global max on opposite colors, minimize both ranges greedily
    int min_side_high = INT_MIN, max_side_low = INT_MAX;
    for (int i = 0; i < N; i++) {
        min_side_high = max(min_side_high, balls[i].first);
        max_side_low = min(max_side_low, balls[i].second);
    }
    ans = (long long)(min_side_high - global_min.first)
        * (global_max.first - max_side_low);

    // put the global min and global max on the same color, minimize range of the other color
    if (global_min.second != global_max.second) {
        multiset<int> other;
        other.insert(balls[global_min.second].second);
        other.insert(balls[global_max.second].first);

        int rem1 = global_min.second, rem2 = global_max.second;
        if (rem1 < rem2) swap(rem1, rem2);
        balls.erase(balls.begin() + rem1);
        balls.erase(balls.begin() + rem2);

        // initially assume that other's min is at minus infinity: just give it the lower of each pair
        for (pair<int, int> p : balls)
            other.insert(p.first);
        ans = min(ans, (long long)(global_max.first - global_min.first)
                * (*other.rbegin() - *other.begin()));

        // now to increase other's min, we need to switch some prefix of the balls from
        // contributing their lower to contributing their heigher
        sort(balls.begin(), balls.end());
        for (int i = 0; i < int(balls.size()); i++) {
            other.erase(other.find(balls[i].first));
            other.insert(balls[i].second);
            ans = min(ans, (long long)(global_max.first - global_min.first)
                    * (*other.rbegin() - *other.begin()));
        }
    }

    cout << ans << endl;

    return 0;
}

