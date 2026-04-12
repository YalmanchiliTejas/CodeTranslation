#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int lli;
using namespace std;
lli LARGE_NUM = 1000000007;

lli len(int x) {
    if (x == 0) return 1LL;
    return 3LL + 2LL * len(x - 1);
}

lli p(int x) {
    if (x == 0) return 1LL;
    return 1LL + 2LL * p(x - 1);
}

lli g(int l, lli x) {
    if (l == 0) return 1LL;

    if (x == 1LL)
        return 0LL;
    lli length = len(l - 1);
    if (1LL < x && x <= length + 1LL)
        return g(l - 1, x - 1LL);
    if (x == length + 2LL)
        return p(l - 1) + 1LL;
    if (length + 2LL < x && x <= 2LL + 2LL * length)
        return p(l - 1) + 1LL + g(l - 1, x - (2LL + length));
    if (x == 3LL + 2 * length)
        return p(l);

    cout << "error: l = " << l << " x = " << x << endl;
    return 0;
}

signed main() {
    int N;
    lli X;
    cin >> N >> X;
    cout << g(N, X) << endl;
}
