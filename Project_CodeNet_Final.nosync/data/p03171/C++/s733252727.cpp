#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
ll a[3000];
ll dp[3000][3000];

// [l, N-1-r] が残っている状態で渡ってきた
ll solve(int l, int r){
    if(l<0 || r<0 || l>=N || r>=N) return INT64_MAX/2;
    if(dp[l][r] != INT64_MAX) return dp[l][r];
    ll ret;
    ret = max(a[l] - solve(l+1, r), a[N-1-r] - solve(l, r+1));
    dp[l][r] = ret;
    return ret;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> a[i];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = INT64_MAX;
        }
    }
    for(int i=0;i<N;i++){
        dp[i][N-1-i] = a[i];
    }

    cout << solve(0,0) << endl;    

    return 0;
}