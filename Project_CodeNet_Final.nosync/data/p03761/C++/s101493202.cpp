#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const int INF = 1 << 28;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    multiset<char> ret1, ret2;
    for (int i = 0; i < s[0].size(); ++i) {
        ret1.insert(s[0][i]);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            auto it = ret1.find(s[i][j]);
            if (it != ret1.end()) {
                ret1.erase(it);
                ret2.insert(s[i][j]);
            }
        }
        ret1 = ret2;
        ret2.clear();
    }
    for (auto &c : ret1) {
        cout << c;
    }
    cout << endl;
    return 0;
}