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

#define MODULO 998244353

int mul(int a, int b) {
    return ((ll)a * b) % MODULO;
}

int add(int a, int b) {
    return ((ll)a + b) % MODULO;
}

int n, a[3000];
int cache[3001][3001];

int count(int index, int s/*, VI as*/) {
    if (s < 0) {
        return 0;
    }
    if (s == 0 && index <= n) {
        // log("found at %d: ", index);
        // for (auto x : as) {
        //     log("%d ", x);
        // }
        // log("\n");
        return n - (index + 1) + 2;
    }
    if (index >= n) {
        return 0;
    }
    if (cache[index][s] >= 0) {
        return cache[index][s];
    }
    // as.push_back(a[index]);
    int ans1 = count(index + 1, s - a[index]/*, as*/);
    // as.pop_back();
    int ans2 = count(index + 1, s/*, as*/);
    return cache[index][s] = add(ans1, ans2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s;
    cin >> n >> s;
    rep(i, 0, n) {
        cin >> a[i];
    }

    // log("add(1,100)=%d", add(1,100));

    // 先找x1,x2...xk，每找到一种，就给答案增加了(x1+1)*(n-(xk+1)+1)种。
    int ans = 0;
    rep(index, 0, n + 1) {
        fill_n(cache[index], s + 1, -1);
    }
    rep(left, 0, n) {
        // VI as;
        // as.push_back(a[left]);
        int ans1 = mul((left + 1), count(left + 1, s - a[left]/*, as*/));
        log("left+1=%d,ans1=%d\n", left + 1, ans1);
        ans = add(ans, ans1);
    }
    cout << ans;
}
