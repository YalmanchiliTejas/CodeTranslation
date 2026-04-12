#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll n;
vector<string> S;
int main() {
    // string ss = "zxxgs";
    // sort(ss.begin(), ss.end());
    // cout << ss << endl;
    // return 0;
    cin >> n;
    S.resize(n);
    rep(i, n) cin >> S[i];

    map<char, ll> mp;
    rep(i, n) {
        map<char, ll> tmp;
        rep(j, S[i].size()) {
            tmp[S[i][j]]++;
        }

        for (int k = 0; k < 26; k++) {
            char target = 'a' + k;
            if (i == 0) {
                mp[target] = tmp[target];
            } else {
                mp[target] = min(mp[target], tmp[target]);
            }
        }
    }

    for (auto v : mp) {
        // cout << v.first << " " << v.second << endl;
        if (v.second > 0) {
            rep(i, v.second) {
                cout << v.first;
            }
        }
    }
    cout << endl;
}