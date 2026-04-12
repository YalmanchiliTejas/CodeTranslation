#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <cstdint>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
using i64 = int64_t;
int main() {
    int n;
    vector<int> a;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    reverse(begin(a), end(a));
    vector<int> lis;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(begin(lis), end(lis), a[i] + 1);
        if (it == end(lis)) {
            lis.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    cout << lis.size() << endl;
    return 0;
}