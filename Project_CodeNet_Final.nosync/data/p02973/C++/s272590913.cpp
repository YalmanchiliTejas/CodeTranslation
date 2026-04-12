#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int n; cin >> n;
    int a[100000];
    rep(i,n) cin >> a[i];
    multiset<int> s;
    s.insert(-a[0]);
    for (int i=1; i < n; i++) {
        auto t = s.upper_bound(-a[i]);
        if (t == s.end()) s.insert(-a[i]);
        else {
            s.erase(t);
            s.insert(-a[i]);
        }
    }
    cout << s.size() << endl;
}