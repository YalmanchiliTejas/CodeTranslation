#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using i64 = int64_t;

int N;
i64 a[50];

bool done() {
    for (int j = 0; j < N; ++j) {
        if (a[j] >= N) return false;
    }
    return true;
}

int main() {
    cin >> N;
    for (int j = 0; j < N; ++j) {
        cin >> a[j];
    }

    i64 ans = 0;
    while (!done()) {
        int idx = 0;
        for (int j = 1; j < N; ++j) {
            if (a[j] > a[idx]) idx = j;
        }

        i64 inc = a[idx] / N;
        for (int j = 0; j < N; ++j) {
            a[j] += inc;
        }
        a[idx] = (a[idx] - inc) % N;

        ans += inc;
    }

    cout << ans << endl;
    return 0;
}
