#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;

int N;
string S[50];

int main() {
    cin >> N;
    rep(i, N) cin >> S[i];

    map<char, int> ans;
    for (int i = 0; i < 26; i++) {
        char t = (char)('a' + i);

        map<char, int> target;

        int cnt = 0;
        bool flag = true;
        rep(j, N) {
            int tmp = 0;
            rep(k, S[j].size()) {
                if (S[j][k] == t) tmp++;
            } 
            if (tmp == 0) flag = false; 

            if (tmp > 0) {
                if (cnt == 0) cnt = tmp;
                else cnt = min(cnt, tmp);
            }
        }

        if (cnt > 0 && flag) {
            ans[t] = cnt;
        }
    }

    for (auto iter = ans.begin(); iter != ans.end(); iter++) {
        // cout << iter->first << iter->second << endl;
        string s1(iter->second, iter->first);
        cout << s1;
    }
    cout << endl;
}