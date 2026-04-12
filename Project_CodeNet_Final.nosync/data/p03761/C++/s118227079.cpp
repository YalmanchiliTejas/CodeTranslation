//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n ; cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<map<char, int>> mp(n);

    int zero_a = 'a';

    map<char, int> tmp;
    rep(i, 26) {
        tmp[char(zero_a+i)] = 0;
    }

    rep(i, n) {
        mp[i] = tmp;
        int len = s[i].size();
        rep(j, len) {
            mp[i][s[i][j]] ++;
        }
    }

    map<char, int> ansmap;
    rep(i, 26) {
        ansmap[char(zero_a+i)] = 50;
    }

    rep(i, n) {
        rep(j, 26) {
            ansmap[char(zero_a+j)] = min(ansmap[char(zero_a+j)], mp[i][char(zero_a +j)]);
        }
    }

    string ans = "";
    rep(i, 26) {
        int num = ansmap[char(zero_a+i)];
        rep(j,num) {
            ans += char(zero_a+i);
        }
    }
    cout << ans << endl;

    return 0;
}
