#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    ll ans = 0;
    ll n = (ll)s.size();
    for(ll i = 0; i < (ll)(1 << (n - 1)); i++) {
        bitset<11> bi(i);
        if(bi.count() != 3) continue;
        vector<string> v;
        string tmp = "";
        for(ll j = 0; j < n; j++) {
            tmp += s[j];
            if(bi[j]) {
                v.push_back(tmp);
                tmp = "";
            }
        } 
        v.push_back(tmp);
        bool ok = true;
        for(ll j = 0; j < v.size(); j++) {
            if(v[j][0] == '0' && v[j].size() != 1) ok = false;
            if(stol(v[j]) > 256LL) ok = false;
        }
        if(ok) ans++;
     }
     cout << ans << endl;
    return 0;
}
