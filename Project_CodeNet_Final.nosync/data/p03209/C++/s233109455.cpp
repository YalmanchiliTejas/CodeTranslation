#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define ll long long  
const long long MOD = 1000000007LL;
long long poww(int n){
    long long a = 1;
    rep(i,n){
        a = a*2;
    }
    return a;
}
int main(){
    int n;
    long long x;
    cin >> n >> x;
    long long dp[55][3];
    dp[0][0] = 1;//P
    dp[0][1] = 0;//B
    dp[0][2] = 1;//合計
    rep(i,52){
        dp[i+1][0] = 2*dp[i][0] + 1;
        dp[i+1][1] = 2*dp[i][1] + 2;
        dp[i+1][2] = dp[i+1][0] + dp[i+1][1];
    }
    long long ans = 0;
    int cnt = n;
    while(x!=0){
        if(x == 1){
            if(cnt == 0){
                ans++;
            }
            x = 0;
            break;
        }
        else if(x < 1+dp[cnt-1][2]){
            x = x-1;
            cnt--;
        }
        else if(x == 1+ dp[cnt-1][2]){
            x = 0;
            ans = ans + dp[cnt-1][0];
            break;
        }
        else if(x == 2+ dp[cnt-1][2]){
            x = 0;
            ans = ans + dp[cnt-1][0] + 1;
            break;
        }
        else if(x == 3 +2*dp[cnt-1][2]){
            x = 0;
            ans = ans + 2*dp[cnt-1][0] + 1;
            break;
        }
        else{
            ans = ans + dp[cnt-1][0] + 1;
            x = x - dp[cnt-1][2] - 2;
            cnt--;
        }   
    }
    cout << ans << endl;
}