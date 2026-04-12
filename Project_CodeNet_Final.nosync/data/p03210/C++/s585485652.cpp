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

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x; cin >> x;
    if (x == 7 || x == 5 || x == 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}