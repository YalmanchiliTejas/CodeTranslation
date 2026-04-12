#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <cassert>

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define irep(i, a, b) for (int i = a; i <= b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    vector<int> b(n);
    rep(i, 0, n) {
        int j = n - i - 1;
        int idx = 0;
        if (i % 2 == 0) {
            idx = i / 2;
        } else {
            idx = n - 1 - i / 2;
        }
        b[idx] = a[j];
    }

    rep(i, 0, n) {
        cout << (i == 0 ? "" : " ") << b[i];
    }
    cout << endl;
    return 0;
}