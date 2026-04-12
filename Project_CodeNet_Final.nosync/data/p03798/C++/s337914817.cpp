#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;
    string s; cin >> s;

    map<char, char> mp;
    mp['S'] = 'W';
    mp['W'] = 'S';
    vector<string> t = {"SS", "SW", "WS", "WW"};

    for (int i = 0; i < 4; ++i) {
        string k = t[i];

        for (int j = 1; j < n - 1; ++j) {
            if (s[j] == 'o') {
                if (k[j] == 'S') {
                    //羊
                    k.push_back(k[j - 1]);
                } else {
                    //狼
                    k.push_back(mp[k[j - 1]]);
                }
            } else {
                if (k[j] == 'S') {
                    //羊
                    k.push_back(mp[k[j - 1]]);
                } else {
                    //狼
                    k.push_back(k[j - 1]);
                }
            }
        }

        bool ok = false;
        if (s[n - 1] == 'o') {
            if (k[n - 1] == 'S') {
                //羊
                if (k[n - 2] == k[0]) {
                    ok = true;
                }
            } else {
                //狼
                if (k[n - 2] != k[0]) {
                    ok = true;
                }
            }
        } else {
            if (k[n - 1] == 'S') {
                //羊
                if (k[n - 2] != k[0]) {
                    ok = true;
                }
            } else {
                //狼
                if (k[n - 2] == k[0]) {
                    ok = true;
                }
            }
        }

        if (!ok) continue;

        if (s[0] == 'o') {
            if (k[0] == 'S') {
                //羊
                if (k[n - 1] == k[1]) {
                    cout << k << endl;
                    return 0;
                }
            } else {
                //狼
                if (k[n - 1] != k[1]) {
                    cout << k << endl;
                    return 0;
                }
            }
        } else {
            if (k[0] == 'S') {
                //羊
                if (k[n - 1] != k[1]) {
                    cout << k << endl;
                    return 0;
                }
            } else {
                //狼
                if (k[n - 1] == k[1]) {
                    cout << k << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;
}