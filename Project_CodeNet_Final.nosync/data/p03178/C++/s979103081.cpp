// Let's bring the sky down :)
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5;
const int M = 1e9 +  7;
ll dp[N][102][2];
string k;
int n, m;
int solve(int idx, int mod, int flag){
    if(idx == n){
        return(mod == 0);
    }
    if(dp[idx][mod][flag] != -1)
        return dp[idx][mod][flag];
    int ans = 0;
    int curDig = (int)(k[idx] - '0');
    if(!flag){
        for(int i = curDig; i >= 0; i--){
            ans = ans + solve(idx + 1, (mod + i) % m, (i < curDig));
            if(ans >= M)
                ans -= M;
        }
    }
    else{
        for(int i = 0; i < 10; i++){
            ans = ans + solve(idx + 1, (mod + i) % m, flag);
            if(ans >= M)
                ans -= M;
        }
    }
    return dp[idx][mod][flag] = ans;
}
int main()
{
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    n = (int)k.size();
    cin >> m;
    memset(dp, -1, sizeof(dp));
    cout << (solve(0, 0, 0) - 1 + M) % M;
return 0;
}
