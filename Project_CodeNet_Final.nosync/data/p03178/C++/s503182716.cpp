#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

const int maxn = 1e5 + 5;
char s[maxn];
int n;
int d;
typedef long long LL;
LL dp[10005][105];
int a[maxn];

const LL mod = 1e9 + 7; 

LL DP(int pos, int m, bool lead, bool limit){
    //cout << pos << " " << m << " " << lead << " " << limit << endl;
    if(pos == n + 1){
        if(!lead and m == 0)
            return 1;
        else
            return 0;
    }
    if(!lead and !limit and dp[pos][m] != -1)
        return dp[pos][m];
    int mx = limit ? a[pos] : 9;
    LL ans = 0;
    for(int i = 0;i <= mx;i++){
        int m1 = (m + i) % d;
        ans += DP(pos + 1, m1, lead && (i == 0), limit && i == a[pos]);
        if(ans >= mod)
            ans -= mod;
    }
    //cout << pos << " " << m << " " << ans << endl;
    if(!limit and !lead) dp[pos][m] = ans;
    return ans;
}

int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for(int i = 1;i <= n;i++){
        a[i] = s[i] - '0';
    }
    cin >> d;
    memset(dp, -1, sizeof(dp));
    cout << DP(1, 0, true, true) << endl;
    for(int i = 1;i <= 2;i++){
        for(int j = 0;j < 4;j++){
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    return 0;
}
