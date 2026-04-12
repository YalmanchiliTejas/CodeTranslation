#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

LL mypow(LL x,LL n){
    LL ans = 1;
    while(n > 0){
        if(n&1){
            ans = (ans*x)%MOD;
        }
        x = (x*x)%MOD;
        n >>= 1;
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;

    vector<vector<LL>> dp(n+1,vector<LL>(n+1,0));
    dp[a-1][0] = 1;

    vector<LL> kaizyo(n+1,1);
    vector<LL> inverse(n+1,1);
    for(LL i = 1; i < n+1; i++){
        kaizyo[i] = (kaizyo[i-1]*i)%MOD;
        inverse[i] = mypow(kaizyo[i],MOD-2);
    }
    
    vector<vector<LL>> di(n+1,vector<LL>(n+1));
    for(LL i = 0; i < n+1; i++){
        for(LL j = 0; j < n+1; j++){
            di[i][j] = mypow((mypow(kaizyo[i],j)*kaizyo[j])%MOD,MOD-2);
        }
    }

    for(LL i = a; i <= b; i++){
        for(LL j = 0; j < n+1; j++){
            dp[i][j] = dp[i-1][j];
            for(LL k = c; k <= d && j-k*i >= 0; k++){
                dp[i][j] += (((((dp[i-1][j-k*i]*kaizyo[n-j+k*i])%MOD)*inverse[n-j])%MOD)*di[i][k])%MOD;
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[b][n] << endl;
    
    return 0;
}