#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<string> S(n);
    rep(i,n) cin >> S.at(i);
    map<char, int> abc;
    rep(i,S.at(0).size()) {
        ++abc[S.at(0).at(i)];
    }
    if (n > 1) {
        for (int i = 1; i < n; ++i) {
            map<char, int> tmp;
            rep(j,S.at(i).size()) {
                ++tmp[S.at(i).at(j)];
            }
            rep(j,26) {
                abc['a' + j] = min(abc['a' + j], tmp['a' + j]);
            }
        }
    }
    string ans;
    for (auto x : abc) {
        rep(i,x.second) ans.push_back(x.first);
    }
    cout << ans << endl;
}
