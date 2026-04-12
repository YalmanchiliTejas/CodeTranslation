#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int ctoi(char c){
    switch (c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
    }
}

int main(){
    string N;
    cin >> N;
    ll K;
    cin >> K;
    ll len = N.size();
    vector<vector<ll> > dp1(len + 1, vector<ll>(4));
    vector<vector<ll> > dp2(len + 1, vector<ll>(4));
    rep(i,len + 1){
        rep(j,4){
            dp1[i][j] = 0;
            dp2[i][j] = 0;
        }
    }
    dp1[1][1] = 1;
    dp2[1][0] = 1;
    dp2[1][1] = ctoi(N[0]) - 1;
    for (ll i = 1; i < len; i++){
        if (ctoi(N[i]) == 0){
            dp1[i + 1][1] = dp1[i][1];
            dp1[i + 1][2] = dp1[i][2];
            dp1[i + 1][3] = dp1[i][3];
            dp2[i + 1][0] = dp2[i][0];
            dp2[i + 1][1] += dp2[i][0] * 9;
            dp2[i + 1][1] += dp2[i][1];
            dp2[i + 1][2] += dp2[i][1] * 9;
            dp2[i + 1][2] += dp2[i][2];
            dp2[i + 1][3] += dp2[i][2] * 9;
            dp2[i + 1][3] += dp2[i][3];
        }
        else{
            dp1[i + 1][1] = dp1[i][0];
            dp1[i + 1][2] = dp1[i][1];
            dp1[i + 1][3] = dp1[i][2];
            dp2[i + 1][1] += dp1[i][0] * (ctoi(N[i]) - 1);
            dp2[i + 1][1] += dp1[i][1];
            dp2[i + 1][2] += dp1[i][1] * (ctoi(N[i]) - 1);
            dp2[i + 1][2] += dp1[i][2];
            dp2[i + 1][3] += dp1[i][2] * (ctoi(N[i]) - 1);
            dp2[i + 1][3] += dp1[i][3];
            dp2[i + 1][0] += dp2[i][0];
            dp2[i + 1][1] += dp2[i][0] * 9;
            dp2[i + 1][1] += dp2[i][1];
            dp2[i + 1][2] += dp2[i][1] * 9;
            dp2[i + 1][2] += dp2[i][2];
            dp2[i + 1][3] += dp2[i][2] * 9;
            dp2[i + 1][3] += dp2[i][3];
        }
    }
    cout << dp1[len][K] + dp2[len][K] << endl;
}