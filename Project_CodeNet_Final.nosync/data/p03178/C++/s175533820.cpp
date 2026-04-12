#include <bits/stdc++.h>
                        
#define endl '\n'
#define int long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FRE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 
using namespace std;
const int mod = 1e9 + 7;
int dp[10005][105][2];
string K;   
int D;
int solve(int i, int sum, int f){
    if(i > K.size())
        return 0;
    if(i == K.size() && sum % D == 0)
        return 1;
    if(i == K.size() && sum % D != 0)
        return 0;
    int &ans = dp[i][sum % D][f];
    if(ans != -1)
        return ans;
    ans = 0;
    if(f == 0){
        for(int j = 0; j < 10; j++){
            ans += solve(i + 1, (sum + j) % D, f);
            ans %= mod;
        }
    }
    else{
        for(int j = 0; j <= (K[i] - '0'); j++){
            ans += solve(i + 1, (sum + j) % D, j == (K[i] - '0'));
            ans %= mod;
        }
    }
    return ans;
}        
int32_t main()
{
    IOS  //FRE

    cin >> K >> D;
    memset(dp, -1, sizeof(dp));
    int temp = solve(0, 0, 1);
    
    cout << (temp - 1 + mod) % mod;
 
   return 0;
}