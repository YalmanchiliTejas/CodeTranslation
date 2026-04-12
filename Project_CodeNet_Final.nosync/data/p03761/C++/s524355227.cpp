#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s.at(i);
    map<char, int> mp;
    for (char c : s.at(0)) mp[c]++;
    for (int i = 1; i < n; ++i) {
        map<char, int> m;
        for (char c : s.at(i)) m[c]++;
        for (auto p : mp) {
            if (m.count(p.first)) {
                mp.at(p.first) = min(p.second, m.at(p.first));
            }
            else mp.at(p.first) = 0;
        }
    }
    stringstream ss;
    for (auto p : mp) {
        rep(i, p.second) ss << p.first;
    }
    cout << ss.str() << endl;
    return 0;
}