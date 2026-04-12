#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n; cin >> n;
    vector<string> s(n);
    vector<ll> sans(26, 9999), ss(26, 0);
    rep(i, n){
        fill(ss.begin(), ss.end(), 0);
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        rep(j, s[i].length()) ss[s[i][j]-'a']++;
        rep(j, ss.size()) sans[j] = min(sans[j], ss[j]);
    }
    rep(i, sans.size()){
        rep(j, sans[i]) printf("%c", (char)('a'+i));
    }
    cout << endl;
    return 0;
}