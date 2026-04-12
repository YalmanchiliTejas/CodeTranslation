#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back
string S;
int K;
int const N = 101;
int dp[N][4][2];

int solve(int i, int k, bool d = 1){    
    if(k > K){
        return 0;
    }
    if(i == S.size()){
        return k == K;
    }
    if(dp[i][k][d] != -1){
        return dp[i][k][d];
    }
    int D = S[i] - '0';
    int ans = 0;
    for(int j = (d) ? D : 9; j >= 0; j--){
        ans += solve(i + 1, k + (j > 0), d&(j == D));
    }
    return dp[i][k][d] = ans;
}
signed main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    memset(dp, -1, sizeof dp);
    cin >> S; cin >> K;
    cout << solve(0,0) << endl;

    return 0;
}