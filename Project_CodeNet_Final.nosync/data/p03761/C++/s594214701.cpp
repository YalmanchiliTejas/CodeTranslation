#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    map<char, int> mp;
    string a = "abcdefghijklmnopqrstuvwxyz";
    rep(i, a.size()) mp[a[i]] = 50;

    rep(i, S.size()) {
        map<char, int> mp2;
        string s = S[i];
        rep(j, s.size()) mp2[s[j]]++;
        rep(i, a.size()) chmin(mp[a[i]], mp2[a[i]]);
    }

    string ans = "";
    rep(i, a.size()) rep(j, mp[a[i]]) ans += a[i];
    cout << ans << endl;
}