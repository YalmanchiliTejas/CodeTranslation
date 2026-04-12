#include<bits/stdc++.h>
using namespace std;

long a[3002];
long long dp[3002][3002] = {};

long long rec(int begin, int end, int turn){
    if(dp[begin][end] != -1) return dp[begin][end];
    if(begin == end) return dp[begin][end] = turn*a[begin];

    long long ret;
    if(turn == 1){
        ret = -1e18;
        ret = max(ret, rec(begin+1, end, -turn) + turn*a[begin]);
        ret = max(ret, rec(begin, end-1, -turn) + turn*a[end]);
    }
    else{
        ret = 1e18;
        ret = min(ret, rec(begin+1, end, -turn) + turn*a[begin]);
        ret = min(ret, rec(begin, end-1, -turn) + turn*a[end]);
    }
    return dp[begin][end] = ret;
}

int main(){
    int N;
    cin >> N;
    for(int n=0;n<N;n++) cin >> a[n];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            dp[i][j] = -1;
        }
    }
    cout << rec(0, N-1, 1) << endl;
    return 0;
}