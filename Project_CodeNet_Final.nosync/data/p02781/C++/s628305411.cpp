#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    string n;
    cin >> n;
    ll k;
    cin >> k;

    vector<vector<array<ll, 2>>> dp(n.size() + 1, vector<array<ll, 2>>(k + 1));
    for(ll p = n.size(); p >= 0; --p){
        for(ll r = 0; r <= k; ++r){
            for(ll s = 1; s >= 0; --s){
                if(r == 0){
                    dp.at(p).at(r).at(s) = 1;
                }else if(p == n.size()){
                    dp.at(p).at(r).at(s) = 0;
                }else if(s == 1){
                    dp.at(p).at(r).at(s) = 9 * dp.at(p + 1).at(r - 1).at(1) + dp.at(p + 1).at(r).at(1);
                }else{
                    ll tmp = 0;
                    const ll d = n.at(p) - '0';
                    if(d > 0){
                        tmp += dp.at(p + 1).at(r - 1).at(0);
                    }
                    if(d > 1){
                        tmp += dp.at(p + 1).at(r - 1).at(1) * (d - 1);
                    }
                    tmp += dp.at(p + 1).at(r).at(d > 0);
                    dp.at(p).at(r).at(s) = tmp;
                }
            }
        }
    }
    cout << dp.at(0).at(k).at(0) << endl;
    return 0;
}
