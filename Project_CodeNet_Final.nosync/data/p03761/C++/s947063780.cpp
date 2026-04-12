#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)b; i++)
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n;
    cin >> n;
    string s[n];
    rep(i, 0, n) {
        cin >> s[i];
    }

    if (n == 1) {
        vector<char> v;
        rep(i, 0, s[0].size()) {
            v.push_back(s[0][i]);
        }
        sort(v.begin(), v.end());
        rep(i, 0, v.size()) {
            cout << v[i];
        }
        cout << endl;
        return 0;
    }

    int common[26] = {};
    rep(i, 0, s[0].size()) {
        rep(j, 0, s[1].size()) {
            if (s[0][i] == s[1][j]) {
                common[s[0][i] - 'a']++;
                break;
            }
        }
    }


    rep(i, 2, n) {
        rep(j, 0, 26) {
            if (common[j]) {
                int cnt = 0;
                rep(k, 0, s[i].size()) {
                    if (s[i][k] == (char)(j + 'a')) {
                        cnt++;
                    }
                }
                common[j] = min(cnt, common[j]);
            }
        }
    }

    string ans;
    rep(i, 0, 26) {
        rep(j, 0, common[i]) {
            ans += (char)(i + 'a');
        }
    }

    cout << ans << endl;
    return 0;
}
