#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll inf = INT64_MAX / 4;
constexpr double pi = asin(1) * 2;
constexpr ll mod = 1000000007;


ll mpow(ll base, ll power) {
    if (power == 0) return 1;
    ll t = mpow(base, power / 2);
    return (t * t * (power % 2 ? base : 1)) % mod;
}

int main() {
    int n, a[100000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int> b;
    for (int i = 0; i < n; i++) {
        auto v = b.lower_bound(a[i]);
        if (b.empty() || v == b.begin()) {
            b.insert(a[i]);
        } else {
            v--;
            b.erase(v);
            b.insert(a[i]);
        }
    }
    cout << b.size() << endl;
}
