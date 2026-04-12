#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <algorithm>
#include <numeric>
#include <limits>
#include <string>
#include <regex>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

ll rec(string N, int K) {
    
    ll m = N.length() - 1;
    ll msd = N[0] - '0';
    if (K == 0) return 1;
    if (N.empty()) {
        return 0;
    }

    ll dd1 = 1;
    ll dr1 = 1;
    ll t1  = 1;
    for (int i = 0; i < K; i++) {
        dd1 *= m - i;
        dr1 *= i + 1;
        t1  *= 9;
    }
    ll dd2 = 1;
    ll dr2 = 1;
    ll t2  = 1;
    for (int i = 0; i < K - 1; i++) {
        dd2 *= m - i;
        dr2 *= i + 1;
        t2  *= 9;
    }
    N.erase(N.begin());
    if (msd == 0) {
        return rec(N, K);
    }
    else {
        return dd1 / dr1 * t1 + (msd - 1) * dd2 / dr2 * t2 + rec(N, K - 1);
    }
}

int main()
{
    string N;
    int K;
    cin >> N;
    cin >> K;
    ll ans = rec(N, K);
    cout << ans << endl;
    
    return 0;
}
