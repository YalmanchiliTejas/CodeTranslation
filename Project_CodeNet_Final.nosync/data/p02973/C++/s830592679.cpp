#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;
using ll=long long int;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e: a) cin >> e;

    vector<int> lds(n, -1);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lds.rbegin(), lds.rend(), a[i]);
        *(it-1) = a[i];
    }
    auto it = upper_bound(lds.rbegin(), lds.rend(), -1);
    int ans = n - (it - lds.rbegin());

    cout << ans << endl;

    return 0;
}
