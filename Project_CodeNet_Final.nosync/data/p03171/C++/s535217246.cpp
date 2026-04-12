#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
typedef long long ll;
using namespace std;
vector<ll> v(3333);
ll dp[3333][3333];

ll f(int l,int r){
    if(l==r)return v[l];
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    return dp[l][r]=max(v[l]-f(l+1,r),v[r]-f(l,r-1));
}

int main(){
    int n;cin>>n;
    for(auto &i:v)cin>>i;
    for(int i=0;i<3333;i++)for(int j=0;j<3333;j++)dp[i][j]=-1;
    cout<<f(0,n-1);
}