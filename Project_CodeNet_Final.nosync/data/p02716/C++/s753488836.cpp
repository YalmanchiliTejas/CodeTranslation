#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<map<int, int> >dp(1000000);
int arr[1000000];
int inf = 1e16;

int solve(int i, int k){
    if(i<0 && k==0)return 0;
    if(i<0)return -inf;
    int aa = (i+1+1)/2;
    if(k > aa)return -inf;
    if(dp[i].find(k) != dp[i].end())return dp[i][k];
    int alpha = max(solve(i-1, k), arr[i]+solve(i-2,k-1));
    return dp[i][k] = alpha;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)cin>>arr[i];
    cout<<solve(n-1, n/2);
    return 0;
}