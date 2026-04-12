#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    ll A;
    ll i;
    ll dp[N+1][3][2];
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    dp[0][1][0]=0;
    dp[0][1][1]=0;
    dp[0][2][0]=0;
    dp[0][2][1]=0;
    for(i=1;i<=N;i++){
        cin >> A;
        dp[i][0][0]=dp[i-1][0][1];
        dp[i][0][1]=dp[i-1][0][0]+A;
        dp[i][1][0]=max(dp[i-1][1][1],dp[i-1][0][0]);
        if(i>1)dp[i][1][1]=dp[i-1][1][0]+A;else dp[i][1][1]=0;
        dp[i][2][0]=max(dp[i-1][2][1],dp[i-1][1][0]);
        if(i>2)dp[i][2][1]=dp[i-1][2][0]+A;else dp[i][2][1]=0;
    }
    if(N%2==0){
        cout << max(dp[N-1][0][1],dp[N][1][1])<<endl;
    }else{
        cout << max(dp[N-2][0][1],max(dp[N-1][1][1],dp[N][2][1]))<<endl;
    }
    return 0;
}
