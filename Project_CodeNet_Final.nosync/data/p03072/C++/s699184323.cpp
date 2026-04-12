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
    vector<int> h(n);
    for (auto &e: h) cin >> e;

    int ans = 1;
    int m = h[0];
    for (int i = 1; i < n; ++i) {
        if (m <= h[i]) {
            ++ans;
            m = h[i];
        }
    }

    cout << ans << endl;

    return 0;
}
