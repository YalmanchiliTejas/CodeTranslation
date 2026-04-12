#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <climits>
#include <random>

#define ll long long

using namespace std;

int main() {
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int n;
    scanf("%d", &n);
    vector<ll> a(n + 1);
    vector<ll> sum(n + 1, 0);
    vector<vector<ll>> d(1 + n + 1, vector<ll>(1 + n + 1, 0));
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            d[i][j] = max(sum[j] + a[i] - sum[i] - d[i + 1][j], sum[j - 1] + a[j] - sum[i - 1] - d[i][j - 1]);
        }
    }
    ll val_1 = d[1][n];
    ll val_2 = (sum[n] - d[1][n]);
    printf("%lld\n", val_1 - val_2);
    return 0;
}