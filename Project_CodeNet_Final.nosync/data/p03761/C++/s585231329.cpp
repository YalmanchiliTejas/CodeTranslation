/**
 *    author:  FromDihPout
 *    created: 2020-06-29
**/

#include <bits/stdc++.h>
using namespace std;


const int INF = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> min_cnt(26, INF);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<int> curr_cnt(26);
        for (char c : s) {
            curr_cnt[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            min_cnt[i] = min(min_cnt[i], curr_cnt[i]);
        }
    }
    
    string ans = "";
    for (int i = 0; i < 26; i++) {
        if (min_cnt[i] != 0) {
            ans.insert(ans.length(), string(min_cnt[i], i + 'a'));
        }
    }
    cout << ans << '\n';
    return 0;
}