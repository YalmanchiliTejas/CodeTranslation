#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    int g[m][2];
    map<vector<int>, int> mp;
    rep(i,m) {
        vector<int> t(2);
        rep(j,2) cin >> t[j];
        mp[t] = -1;
    }
    vector<int> a(n-1);
    rep(i,n-1) a[i] = i+2;
    int ans = 0;
    do {
        bool ok = true;
        vector<int> b(2);
        b[0] = 1; b[1] = a[0];
        if (mp.find(b) == mp.end()) ok = false;
        for (int i = 0; i < n-2; i++) {
            vector<int> t(2);
            for (int j = i; j < i+2; j++) {
                t[j-i] = a[j];
            }
            sort(t.begin(), t.end());
            if (mp.find(t) == mp.end()) ok = false;
        }
        if (ok) ans++;
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
    return 0;
}
