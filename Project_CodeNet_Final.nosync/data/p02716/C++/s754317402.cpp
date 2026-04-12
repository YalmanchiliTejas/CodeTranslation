#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

#define ll long long
#define el '\n'
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define VI vector<int>
#define VII vector<pair<int, int>>
#define PII pair<int, int>
#define MP make_pair
// #define log(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define log(fmt, ...)
// #define check(...) assert(##__VA_ARGS__)
#define check(...)

#define INF (ll)1e15

int n;
int a[200000];
int min_dist = 100;
int max_dist = -100;

ll cache[5][5][200000];
ll total = 0, total_hit = 0;

ll solve(int index, int choose, int gap_left) {
    total++;
    max_dist = max(max_dist, index - 2 * choose);
    min_dist = min(min_dist, index - 2 * choose);
    if (choose >= n / 2) {
        return 0;
    }

    int k = index - 2 * choose;
    if (cache[k][gap_left][index] != -INF) {
        total_hit++;
        return cache[k][gap_left][index];
    }
    ll ans = a[index] + solve(index + 2, choose + 1, gap_left);
    if (gap_left > 0) {
        ans = max(ans, solve(index + 1, choose, gap_left - 1));
    }
    return cache[k][gap_left][index] = ans;
}

int myrandom() {
    if (rand() > RAND_MAX / 2) {
        return (int)(rand() * 1.0 / RAND_MAX * 1e9);
    } else {
        return -(int)(rand() * 1.0 / RAND_MAX * 1e9);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // log("RAND_MAX = %d", RAND_MAX);

    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        // a[i] = myrandom();
        // log("%d ", a[i]);
    }
    // log("\n");

    rep(i, 0, 5) {
        rep(j, 0, 5) {
            fill_n(cache[i][j], n, -INF);
        }
    }

    if (n % 2 == 0) {
        cout << solve(0, 0, 1);
    } else {
        cout << solve(0, 0, 2);
    }

    log("\n");
    log("max dist = %d\n", max_dist);
    log("min dist = %d\n", min_dist);
    log("total = %lld\n", total);
    log("total hit = %lld\n", total_hit);
}
