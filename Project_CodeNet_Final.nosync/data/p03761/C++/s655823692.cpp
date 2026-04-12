#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }


int main() {
    int n; cin >> n;
    vector<vector<int>> string_count(n, vector<int>(26, 0));
    rep(i, n) {
        string s; cin >> s;
        rep(j, s.size()) {
            string_count[i][s[j]-'a']++;
        }
    }


    string ans = "";
    rep(j, 26) {
        int alph_min = INT_MAX;
        rep(i, n) chmin(alph_min, string_count[i][j]);
        ans += string(alph_min, 'a' + j) ;
    }

    cout << ans << endl;

    return 0;
}


