#include<bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define print(x) cout << (x) << endl;
#define printa(x, n) for(ll i = 0; i < n; i++) {cout << (x[i]) << " ";} cout << endl;
using namespace std;
using ll = long long;

int main(void) {
    int n;
    cin >> n;

    map<char, int> mp;

    rep (i, n) {
        string s;
        cin >> s;
        map<char, int> m;
        rep (j, s.size()) {
            if (i == 0) mp[s[j]]++;
            else {
                
                m[s[j]]++;
                
            }
        }
        if (i == 0) continue;
        for (char c = 'a'; c <= 'z'; c++) {
            mp[c] = min(mp[c], m[c]);
        }
    }

    vector<char> ans;

    for (char c = 'a'; c <= 'z'; c++) {
        //cout << c << " " << mp[c] << endl;
        rep (i, mp[c]) {
            ans.push_back(c);
        }
    }

    sort(ans.begin(), ans.end());

    rep (i, ans.size()) cout << ans[i];
    cout << endl;
    
    return 0;
}