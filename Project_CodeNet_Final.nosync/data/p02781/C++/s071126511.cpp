#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll getKthNum(string N, int k){
    return N[k] - '0';
}

int main(){
    string N;  ll K;
    cin >> N >> K;
    ll L = N.length();
    vector<vector<ll>> dp0(L+1, vector<ll>(K+1, 0));
    vector<vector<ll>> dp1(L+1, vector<ll>(K+1, 0));
    dp1[0][0] = 1;
    for(int i=1; i<=L; i++) for(int j=0; j<=K; j++){
        ll val = getKthNum(N, i-1);
        if(val == 0){
            dp1[i][j] += dp1[i-1][j];
        }else if(j > 0){
            dp1[i][j] += dp1[i-1][j-1];
        }

        dp0[i][j] += dp0[i-1][j];
        if(val > 0){
            dp0[i][j] += dp1[i-1][j];
        }
        if(j>0){
            dp0[i][j] += dp0[i-1][j-1]*9 + dp1[i-1][j-1]*max(0ll, val - 1);
        }
        // cout << i << " " << j << " " << dp0[i][j] << " " << dp1[i][j] << endl;
    }
    cout << dp0[L][K] + dp1[L][K] << endl;
}
