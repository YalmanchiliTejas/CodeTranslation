#pragma GCC optimize("O3,no-stack-protector")
// 実数の場合
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("avx")
// AtCoder新ジャッジ以降
// #pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

bool isOK(const vector<Int> &A, int index, Int key) {
    if (A[index] < key) {
        return true;
    } else {
        return false;
    }
}

int b_search(const vector<Int> &A, Int key) {
    int ng = -1;
    int ok = (int)A.size();

    while (ok - ng > 1) {
        int mid = ng + (ok - ng) / 2;

        if (isOK(A, mid, key)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Int> a(n), ans(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ans[0] = a[0];
    int color = 1;
    for (int i = 1; i < n; i++) {
        auto index = b_search(ans, a[i]);
        if (ans[index] == -1) {
            ans[color] = a[i];
            color++;
        } else {
            ans[index] = a[i];
        }
    }

    cout << color << endl;

    return 0;
}
