#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll n; cin >> n;
    vector<string> v;
    ll ans[1000]={0}, garbo[1000] = {0};
    for(ll i = 0; i < n; ++i){
        string tmp; cin >> tmp;
        v.push_back(tmp);
    }
    for(ll i = 0; i < v[0].length(); ++i){
        ans[v[0][i]]++;
    }
    for(ll i = 1; i < n; ++i){
        for(ll j = 0; j < v[i].length(); ++j){
            garbo[v[i][j]]++;
        }
        for(ll j = 0; j < 1000; ++j){
            ans[j] = min(ans[j], garbo[j]);
        }
        memset(garbo, 0, sizeof(garbo));
    }
    for(ll i = 0; i < 1000; ++i){
        if(ans[i] != 0){
            for(ll j = 0; j < ans[i]; ++j){
                cout << char(i);
            }
        }
    }
    return 0;
}
