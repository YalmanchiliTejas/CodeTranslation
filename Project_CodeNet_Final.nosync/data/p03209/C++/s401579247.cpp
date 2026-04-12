#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = 60;
const int MOD = (int) 1e9 + 7;

ll a[Maxn], p[Maxn];

ll rec(int level, ll n) {
    if (level == 0) {
        if (n >= 1) return 1;
        else return 0;
    }
    if (n == 1) return 0;
    if (n <= a[level - 1] + 1) {
        return rec(level - 1, n - 1);
    }
    return p[level - 1] + 1 + rec(level - 1, n - 2 - a[level - 1]);
}

int n;
ll x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    a[0] = 1;
    p[0] = 1;
    for (int i = 0; i < n; ++i) {
        a[i + 1] = 2 * a[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }

    cout << rec(n, x) << endl;
}
