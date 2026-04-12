//Atcoder
#include <bits/stdc++.h>
#define inp "inp"
#define out "out"
#define MOD 1000000007
#define MAGIC 1000
using namespace std;
string s;
long long  D,dp[10005][105][5];
vector <long long > digits;
long long  DP (long long  id,long long  summod,long long  tight){
    if (id == -1) return (summod == 0) ? 1 : 0;
    if (dp[id][summod][tight] != -1 && tight == 0) return dp[id][summod][tight];
    long long  zz = 9;
    if (tight == 1) zz = digits[id];
    long long  res = 0;
    for (long long  i = 0; i <= zz; i++){
        long long  newTight = 0;
        if (i == digits[id]) newTight = tight;
        res += DP(id-1,(summod + i) % D,newTight);
        res = (res + MOD) % MOD;
    }
    if(tight == 0) dp[id][summod][tight] = res;
    return res;
}
main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> s;
    cin >> D;
    if (s == "0") cout << 0;
    memset(dp,-1,sizeof(dp));
    for (long long  i = s.size()-1; i >= 0; i--) digits.push_back(s[i]-48);
    long long ans = DP(digits.size()-1,0,1) - 1;
    if (ans == -1 ) cout << MOD - 1;
    else cout << (ans + MOD)%MOD;
}
