#include <bits/stdc++.h>
using namespace std;
#define REP(i,x,n) for(int i = x; i < n; i++)
#define MAX 1000000001


int a,b,c,x,y;
// int dp[100001][100001];

int main(void){
    cin >> a >> b >> c >> x >> y;
    // int res = MAX;
    // dp[1][0] = 1500;
    // dp[0][1] = 2000;
    // dp[1][1] = 3200;
    int ans = MAX;
    REP(i,0,(x+y+1)) {
        ans = min(i * 2*c + max(0,x-i)*a + max(0,y-i)*b,ans);
    }
    
    cout << ans << endl;

}