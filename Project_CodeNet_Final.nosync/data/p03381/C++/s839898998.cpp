#include <bits/stdc++.h>
using namespace std;
 
using Int = long long;
#define rep(i, n) for (Int i = 0; i < Int(n); ++i)
#define rep1(i, n) for (Int i = 1; i <= Int(n); ++i)
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Int n;
    cin >> n;
    vector<pair<Int, Int>> x(n);
    rep(i, n) {
        Int v;
        cin >> v;
        x[i] = {v, i};
    }
    sort(begin(x), end(x));
    vector<Int> ord(n);
    rep(i, n) ord[x[i].second] = i;
    rep(i, n) cout << (ord[i] < n / 2 ? x[n / 2].first : x[n / 2 - 1].first)
                   << endl;
}
