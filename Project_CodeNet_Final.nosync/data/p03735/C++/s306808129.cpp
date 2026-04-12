#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000, INDEX = 1;
const int MAX_VAL = 1000000000, INF = MAX_VAL + 1;

struct Ball {
    int bag;
    long long val;

    Ball() {
        ;
    }

    Ball(int bag, long long val) {
        this->bag = bag;
        this->val = val;
    }

    friend bool operator < (const Ball &a, const Ball &b) {
        if (a.val == b.val) {
            return a.bag < b.bag;
        }

        return a.val < b.val;
    }
};

int n;
long long x[MAX_N + INDEX], y[MAX_N + INDEX];

Ball balls[2 * MAX_N + INDEX];
bool usedBag[MAX_N + INDEX];

long long ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    long long max_max = 0, max_min = 0, min_max = INF, min_min = INF;
    for (int i = 1; i <= n; i++) {
        max_max = max(max_max, max(x[i], y[i]));
        max_min = max(max_min, min(x[i], y[i]));
        min_max = min(min_max, max(x[i], y[i]));
        min_min = min(min_min, min(x[i], y[i]));
    }

    ans = (max_max - min_max) * (max_min - min_min);

    for (int i = 1; i <= n; i++) {
        balls[2 * i - 1] = Ball(i, x[i]);
        balls[2 * i] = Ball(i, y[i]);
    }

    sort(balls + INDEX, balls + INDEX + 2 * n, less<Ball>());

    int r = 2 * n + 1;
    while (!usedBag[balls[r - 1].bag]) {
        r--;

        usedBag[balls[r].bag] = true;
    }

    for (int l = 1; l <= 2 * n; l++) {
        while (r <= 2 * n && usedBag[balls[l].bag]) {
            usedBag[balls[r].bag] = false;

            r++;
        }

        usedBag[balls[l].bag] = true;

        if (r > 2 * n) {
            break;
        }

        ans = min(ans, (balls[2 * n].val - balls[1].val) * (balls[r - 1].val - balls[l + 1].val));
    }

    cout << ans << endl;

    return 0;
}
