#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;
ll dp[3333][3333];
ll v[3333];

ll solve(int l,int r){
    if(l>r)return 0;
    if(l==r)return v[l];
    if(dp[l][r]!=-ll(1e18))return dp[l][r];
    return (dp[l][r]=max(v[l]-solve(l+1,r),v[r]-solve(l,r-1)));
    
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<3333;i++)for(int j=0;j<3333;j++)dp[i][j]=-ll(1e18);
    cout<<solve(0,n-1);
    
}