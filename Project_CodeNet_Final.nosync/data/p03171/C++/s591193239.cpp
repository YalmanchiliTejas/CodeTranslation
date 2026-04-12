#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
using namespace std;

vector<vector<ll>> dp;
vector<int> a;

ll solve(int s, int g, int N){
    if(dp[s][g] != 1e18) return dp[s][g];

    if((N-(g-s+1))%2==0){
        // 太郎君の手
        dp[s][g] = max(solve(s+1,g,N) + a[s], solve(s, g-1, N) + a[g]);
    }else{
        dp[s][g] = min(solve(s+1,g,N) - a[s], solve(s, g-1, N) - a[g]);
    }
    return dp[s][g];
}

int main(){
    int N;  cin >> N;
    a.resize(N,0);
    for(int i=0; i<N; i++) cin >> a[i];

    dp.resize(N, vector<ll>(N, 1e18));
    for(int i=0; i<N; i++){
        if((N-1)%2==0)
            dp[i][i] = a[i];
        else
            dp[i][i] = -a[i];
    }

    cout << solve(0, N-1, N) << endl;
}
