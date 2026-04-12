#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll dp[3001][3001];

ll solve(vector<int> &a, int i, int j, int turn){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(turn==0)
        return dp[i][j] = max(a[i]+solve(a,i+1,j,1), a[j]+solve(a,i,j-1,1));
    return min(solve(a,i+1,j,0), solve(a,i,j-1,0));
}

int main(){
    cin>>n;
    memset(dp, -1, sizeof dp);
    ll sum = 0;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    ll X = solve(a,0,n-1,0);
    ll Y = sum-X;
    cout<<(X-Y)<<endl;
    return 0;
}
