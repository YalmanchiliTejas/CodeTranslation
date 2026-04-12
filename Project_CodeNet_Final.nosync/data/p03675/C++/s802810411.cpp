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

int N, a[200000];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    for (int j = 0; j < N; ++j) {
        cin >> a[j];
    }

    int b[200000];

    int li = 0, ri = N-1;
    for (int j = 0; j < N; ++j) {
        if (j % 2 == 0) {
            b[li] = a[N-1-j];
            li++;
        } else {
            b[ri] = a[N-1-j];
            ri--;
        }
    }

    for (int j = 0; j < N; ++j) {
        if (j > 0) cout << ' ';
        cout << b[j];
    }
    cout << endl;
    return 0;
}
