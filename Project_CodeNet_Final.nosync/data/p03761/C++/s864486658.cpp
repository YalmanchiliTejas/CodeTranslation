#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<vector<int>> cnt(n, vector<int>(26));
    rep(i,n){
        for(int j = 0; j < s[i].size(); ++j){
            cnt[i][s[i][j]-'a']++;
        }
    }
    string ans = "";
    for(int i = 0; i < 26; ++i){
        char c = 'a'+i;
        int m = 100;
        for(int j = 0; j < n; ++j){
            m = min(m, cnt[j][i]);
        }
        rep(i,m) ans += c;
    }
    cout << ans << endl;
}