#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> mp(26, 0);
    rep(i, 0, n){
        string s;
        cin >> s;
        vector<ll> t(26, 0);
        for(auto e : s){
            t[e-'a']++;
        }
        rep(j, 0, 26){
            if(i != 0) mp[j] = min(mp[j], t[j]);
            else mp[j] = t[j];
        }
    }
    rep(i, 0, 26){
        rep(j, 0, mp[i]) cout << (char)('a' + i);
    }
    cout << endl;
    return 0;
}