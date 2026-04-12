#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <list>
#include <set>
using namespace  std;

#define int long long int

constexpr int INF = std::numeric_limits<int>::max();

int barg[60];
int meet[60];

int N, X;

int calc(int x, int l) {
    if (x == 0) {
        return 0;
    }

    if (x == barg[l]) {
        return meet[l];
    }

    if (x >= barg[l-1] + 2 ) {
        return meet[l-1] + 1 + calc(x - barg[l-1] - 2, l - 1);
    } else {
        return calc(x - 1, l - 1);
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> X;

    barg[0] = 1;
    meet[0] = 1;
    for (int i = 1; i <= N; i++) {
        barg[i] = 2 * barg[i-1] + 3;
        meet[i] = 2 * meet[i-1] + 1;
    }
    cout << endl;

    cout << calc(X, N) << endl;
}