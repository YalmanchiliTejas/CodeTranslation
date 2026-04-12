#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    multiset<int> s;
    rep(i,n) {
        auto id = s.lower_bound(a[i]);
        if (id != s.begin()) s.erase(--id);
        s.insert(a[i]);
    }
    int ans = s.size();
    cout << ans << endl;
    return 0;
}