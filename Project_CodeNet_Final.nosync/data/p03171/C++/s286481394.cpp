#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long double ld;

lli n;
lli a[3003];
lli dp[2][3003][3003];

lli func(int t,lli l,lli r){
    if(r<l) return 0;
    if(dp[t][l][r]!=-1) return dp[t][l][r];
    
    if(t==0){
        return dp[t][l][r]=max(a[l]-func(1,l+1,r) , a[r]-func(1,l,r-1));
    }
    else{
        return dp[t][l][r]=max(a[l]-func(0,l+1,r) , a[r]-func(0,l,r-1));
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    lli i,j,l;
    for(i=0;i<n;i++) cin>>a[i];
    
    lli ans=max(a[0]-func(1,1,n-1) , a[n-1] - func(1,0,n-2));
    cout<<ans<<endl;
}
