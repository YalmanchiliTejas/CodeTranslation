#include <bits/stdc++.h>
using namespace std;

long long int turno;
const long long int MAX=3003;
long long int dp[MAX][MAX];
long long int arr[MAX];

long long int solve(long long int left, long long int right, long long int turno){
    if(dp[left][right]!=-1) return dp[left][right];
    if(left>right) return 0;
    if(turno==1){
        return dp[left][right]=max(arr[left]+solve(left+1, right, 0), arr[right]+solve(left, right-1, 0));
    }
    else return dp[left][right]=min(solve(left+1, right, 1)-arr[left], solve(left, right-1, 1)-arr[right]);
}

int main(void){
    long long int n;
    cin>>n;
    for(long long int i=0;i<n;i++) cin>>arr[i];
    memset(dp, -1, sizeof dp);
    cout<<solve(0, n-1, 1)<<endl;

    return 0;
}
