#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
 
int main() { 
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a.at(i);
    }

    vector<int64_t> r(n + 1, 0);
    for (int i = 0; i < n; i++) {
        r.at(i + 1) = r.at(i) + a.at(n - i - 1);
        r.at(i + 1) %= MOD;
    }

    // for (int i = 0; i < n + 1; i++) {
    //     cout << r.at(i) << endl;
    // }

    int64_t ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int64_t x = a.at(i) * r.at(n - i - 1);
        x %= MOD;
        ans += x;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}