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

ll rec(int l, ll x) {
    if (l == 0) {
        if (x >= 1) return 1;
        else return 0;
    }
    if (x <= a[l - 1] + 1) {
        return rec(l - 1, x - 1);
    } else {
        return p[l - 1] + 1 + rec(l - 1, x - a[l - 1] - 2);
    }
}

int n;
ll x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    a[0] = p[0] = 1;
    for (int i = 0; i < n; ++i) {
        a[i + 1] = 2 * a[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }

    cout << rec(n, x) << endl;
}
