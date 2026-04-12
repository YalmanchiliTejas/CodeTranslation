#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
 
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
 
    vector<pair<int, int>> ud(n), du(n);
    ud[0] = make_pair(1, 0);
    du[0] = make_pair(-1, 0);
    for (int i = 1; i < n; ++i) {
        if (i % 2 == 0) {
            ud[i] = make_pair((i == n - 1 ? 1 : 2), i);   // up
            du[i] = make_pair((i == n - 1 ? -1 : -2), i); // down
        }
        else {
            ud[i] = make_pair((i == n - 1 ? -1 : -2), i); // down
            du[i] = make_pair((i == n - 1 ? 1 : 2), i);   // up
        }
    }
    sort(ud.begin(), ud.end());
    sort(du.begin(), du.end());
 
    ll sum_ud = 0, sum_du = 0;
    for (int i = 0; i < n; ++i) {
        sum_ud += ud[i].first * a[i];
        sum_du += du[i].first * a[i];
    }
 
    cout << max(sum_ud, sum_du) << endl;
 
    return 0;
}