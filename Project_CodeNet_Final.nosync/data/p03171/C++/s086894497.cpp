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
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

void rec(vector<vector<vector<ll>>> &dp,const vector<ll> &a,int turn, int front, int back, ll n){
    if(front + back >= n){
        dp[front][back][turn] = 0;
        dp[front][back][turn^1] = 0;
        return;
    }

    if(turn == 0){
        ll f;
        if(dp[front+1][back][turn^1] < 0) rec(dp,a,turn^1,front+1,back,n);
        f = dp[front+1][back][0] + a[front] - dp[front+1][back][1];
        ll b;
        if(dp[front][back+1][turn^1] < 0) rec(dp,a,turn^1,front,back+1,n);
        b = dp[front][back+1][0] + a[n-back-1] - dp[front][back+1][1];
        if(f > b){
            dp[front][back][0] = dp[front+1][back][0] + a[front];
            dp[front][back][1] = dp[front+1][back][1];
        }else{
            dp[front][back][0] = dp[front][back+1][0] + a[n-back-1];
            dp[front][back][1] = dp[front][back+1][1];
        }
    }else{
        ll f;
        if(dp[front+1][back][turn^1] < 0) rec(dp,a,turn^1,front+1,back,n);
        f = dp[front+1][back][0] - (dp[front+1][back][1] + a[front]);
        ll b;
        if(dp[front][back+1][turn^1] < 0) rec(dp,a,turn^1,front,back+1,n);
        b = dp[front][back+1][0] - (dp[front][back+1][1] + a[n-back-1]);
        if(f > b){
            dp[front][back][0] = dp[front][back+1][0];
            dp[front][back][1] = (dp[front][back+1][1] + a[n-back-1]);
        }else{
            dp[front][back][0] = dp[front+1][back][0];
            dp[front][back][1] = (dp[front+1][back][1] + a[front]);
        }
    }
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(2,-1)));

    rec(dp,a,0,0,0,n);

    cout << dp[0][0][0] - dp[0][0][1] << endl;
    
    return 0;
}