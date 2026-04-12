#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <deque>

using namespace std;
#define int long long

const int mod = 998244353;

int32_t main() {
    int n, x, m;
    cin >> n >> x >> m;
    deque<int> a;
    a.push_back(x);
    a.push_back((x * x) % m);
    set<int> s;
    s.insert(x);
    while(!s.count(a.back())) {
        s.insert(a.back());
        a.push_back((a.back() * a.back()) % m);
    }
    int ans = 0;
    int all = 0;
    while(n && a.front() != a.back()) {
        ans += a.front();
        --n;
        a.pop_front();
    }
    if (n == 0) {
        cout << ans;
        return 0;
    }
    a.pop_back();
    for(int i = 0; i < a.size(); ++i) {
        all += a[i];
    }
    int cnt = n / a.size();
    ans += cnt * all;
    int last = cnt * a.size();
    for(int i = last; i < n; ++i) {
        ans += a[i % a.size()];
    }
    cout << ans;
}
