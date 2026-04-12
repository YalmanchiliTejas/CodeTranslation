#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>

using namespace std;
using boost::sort;
using boost::adaptors::reversed;

int main() {
    long n, x, m;
    cin >> n >> x >> m;
    vector<long> a, s;
    unordered_map<long, long> ls;
    a.push_back(-1);
    a.push_back(x);
    s.push_back(0);
    s.push_back(x);
    ls[x] = 1;
    long l = 1, r = n;
    for (long i = 1; i < n; i++) {
        long an1 = a[i] * a[i] % m;
        a.push_back(an1);
        s.push_back(an1 + s[i]);
        if (ls[an1] > 0) {
            l = ls[an1];
            r = i + 1;
            break;
        } else {
            ls[an1] = i + 1;
        }
    }
    long ans = 0;
    n -= l;
    ans += s[l];
    if (l < r) {
        ans += (s[r] - s[l]) * (n / (r - l));
        ans += s[l + n % (r - l)] - s[l];
    }
    cout << ans << endl;
}
