#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (i64 (Itr) = a; (Itr) < b; (Itr) += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)

#include "bits/stdc++.h"
using i64 = long long;
using namespace std;

i64 n, x, m;

int main() {
    cin >> n >> x >> m;

    vector<vector<i64>> a(64, vector<i64>(m + 1));
    vector<vector<i64>> sum(64, vector<i64>(m + 1));

    repeat(i, m + 1) {
        a[0][i] = i * i % m;
    }
    repeat(k, 1, 64) {
        repeat(i, m + 1) {
            a[k][i] = a[k - 1][a[k - 1][i]];
        }
    }

    repeat(i, m + 1) {
        sum[0][i] = i * i % m;
    }
    repeat(k, 1, 64) {
        repeat(i, m + 1) {
            sum[k][i] = sum[k - 1][i] + sum[k - 1][a[k - 1][i]];
        }
    }

    n--;
    i64 ans = x;
    i64 cnt = 0;
    while (n) {
        if (n & 1) {
            ans += sum[cnt][x];
            x = a[cnt][x];
        }
        cnt++;
        n >>= 1;
    }

    cout << ans << endl;

    return 0;
};