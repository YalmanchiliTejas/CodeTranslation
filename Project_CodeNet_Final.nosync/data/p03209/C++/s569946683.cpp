#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;
using i64=long long int;

i64 lens[51];
i64 pn[51];

i64 fn(i64 n, i64 x) {
    if (x == lens[n]) return pn[n];
    i64 ret = 0;
    --x;
    if (x > 0) {
        ret += fn(n-1, min(lens[n-1], x));
        x -= lens[n-1];
    }
    if (x > 0) {
        ret += 1;
        --x;
    }
    if (x > 0) {
        ret += fn(n-1, min(lens[n-1], x));
    }
    return ret;
}

int main() {
    i64 N, X;
    cin >> N >> X;

    lens[0] = 1;
    pn[0] = 1;
    for (int i = 1; i <= N; ++i) {
        lens[i] = lens[i-1]*2+3;
        pn[i] = pn[i-1]*2+1;
    }

    cout << fn(N, X) << endl;

    return 0;
}
