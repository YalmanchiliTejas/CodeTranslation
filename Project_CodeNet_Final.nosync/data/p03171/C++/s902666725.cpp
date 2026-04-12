#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int a[3300];
Int dp[3300][3300];
Int n;

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n;i++)dp[i][i] = 0;

    for(int width = 1;width <= n;width++){
        for(int l = 0;l + width <= n;l++){
            int r = l + width;
            if(width % 2 == n % 2){//tarou
                dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
            }
            else{//jirou
                dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
            }
        }
    }

    cout << dp[0][n] << endl;
    
    return 0;
}