#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    vector<vector<ll>> dp1(n+1,vector<ll>(k+1)), dp2(n+1,vector<ll>(k+1));
    dp1.at(0).at(0) = 1;

    rep(i,n) {
        int d = s.at(i) - '0';
        if(d==0){
            rep(j,k+1){
                dp1.at(i+1).at(j) = dp1.at(i).at(j);
            }
        } else {
            rep(j,k+1){
                dp2.at(i+1).at(j) += dp1.at(i).at(j);
            }
            rep(j,k){
                dp1.at(i+1).at(j+1) = dp1.at(i).at(j);
                dp2.at(i+1).at(j+1) += dp1.at(i).at(j) * (d-1);
            }
        }
        
        rep(j,k+1){
            dp2.at(i+1).at(j) += dp2.at(i).at(j);
        }
        rep(j,k){
            dp2.at(i+1).at(j+1) += dp2.at(i).at(j) * 9;
        }
        // rep(j,k+1){
        //     cout << dp1.at(i).at(j) << " ";
        // }
        // cout << endl;
    }
    ll ans = dp1.at(n).at(k) + dp2.at(n).at(k);
    cout << ans << endl;
    return 0;
}