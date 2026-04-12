//
// Created by Pulak on 29-11-2019.
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector <int> a;
int dp[3005][3005][2];
int play(int left, int right, int player){
    if(left > right) return 0;
    if(left == right){
        if(player == 0) return a[left];
        else return 0;
    }
    if(dp[left][right][player] != -1) return dp[left][right][player];
    
    if(player == 0)
        return dp[left][right][player] = max(a[left] + play(left + 1, right, 1 - player), a[right] + play(left, right - 1, 1 - player));
    return dp[left][right][player] = min(play(left + 1, right, 1 - player), play(left, right - 1, 1 - player));
}



signed main(){
    
    cin >> n;
    a.resize(n);
    int sum = 0;
    memset(dp, - 1, sizeof(dp));
    for(int i = 0; i <  n ; i++) {cin >> a[i];
        sum += a[i];
    }
    cout << 2 * play(0 , n - 1, 0) - sum<< endl;
    
}