#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 0x1fffffffffffffff;
template<class T> bool chmin(T& a, const T& b){ if(a > b){ a = b; return 1; } return 0; }

int main(){
    ll n;
    cin >> n;
    vector<ll> min(26, INF);
    for(ll i = 0; i < n; i++){
        string s;
        cin >> s;
        vector<ll> cnt(26);
        for(auto& i : s) cnt[i - 'a']++;
        for(ll i = 0; i < 26; i++) chmin(min[i], cnt[i]);
    }
    for(ll i = 0; i < 26; i++) for(ll j = 0; j < min[i]; j++) cout << char('a' + i);
    cout << endl;
}