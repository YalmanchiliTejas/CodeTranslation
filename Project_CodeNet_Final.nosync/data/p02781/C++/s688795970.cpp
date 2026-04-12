#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string N;
int K;

vector<vector<ll>> dp0(101 + 1, vector<ll>(3 + 1, 0));

vector<vector<ll>> dp1(101 + 1, vector<ll>(3 + 1, 0));

void solve(){
    int L = N.size();
    for(int i = 0; i < L; ++i){
        dp1[i][0] = 1;
    }
    dp1[L][0] = 0;
    for(int i = 1; i <= L; ++i){
        for(int j = 0; j <= K; ++j){
            ll a = (ll)(N[i - 1] - '0');

            ll _dp0 = dp0[i - 1][j];
            if(j > 0) _dp0 += 9 * dp0[i - 1][j - 1];
            if(a > 1 && j > 0) _dp0 += (a - 1) * dp1[i - 1][j - 1];
            if(a > 0) _dp0 += dp1[i - 1][j];

            ll _dp1 = 0;
            if(a == 0) _dp1 += dp1[i - 1][j];
            else if(j > 0) _dp1 += dp1[i - 1][j - 1];

            dp0[i][j] = _dp0;
            dp1[i][j] = _dp1;
        }
    }
    cout << dp0[L][K] + dp1[L][K];
}

int main(){
    cin >> N >> K;
    solve();
    return 0;
}