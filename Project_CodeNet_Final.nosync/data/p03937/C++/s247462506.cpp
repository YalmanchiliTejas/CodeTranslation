//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

int main() {
    int h, w;
    cin >> h >> w;
    map<int, int> mp;
    bool flag = true;
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if (s[j] == '#' && mp[i+j] > 0) {
                flag = false;
                break;
            } else if (s[j] == '#') {
                mp[i+j]++;
            }
        }
    }
    string ans = flag ? "Possible" : "Impossible";
    cout << ans << endl;
    return 0;
}