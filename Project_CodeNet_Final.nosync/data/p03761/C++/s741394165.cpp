#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vector<vector<ll>> cnt(26, vector<ll>(n,0));
    rep(i, 0, n) {
        rep(j, 0, s[i].size()) cnt[s[i][j]-'a'][i]++;
    }
    string ans;
    rep(i, 0, 26) {
        ll mn = *min_element(cnt[i].begin(), cnt[i].end());
        rep(j, 0, mn) ans.push_back(i+'a');
    }
    cout << ans << endl;
    return 0;
}