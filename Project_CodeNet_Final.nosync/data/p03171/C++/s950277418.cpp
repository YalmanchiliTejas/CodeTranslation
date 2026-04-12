//length of the longest path in a directed acyclic graph
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9+5;

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(j == i) dp[i][j] = a[i];
            else dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1];
}