#include<bits/stdc++.h>

using namespace std;

long long int dp[3002][3002][2];
int arr[3002];
int n;
long long int fun(int i,int j ,int f){
    // cout<<i<<" "<<j<<endl;
    if(i==j){
        if(f==1) return -arr[i];
        else return arr[i];
    }
    
    if(dp[i][j][f]!=-1)return dp[i][j][f];
    
    int kk;
    if(f==1){
        kk=-1;
        return dp[i][j][f]=min(kk*arr[i]+fun(i+1,j,1-f),kk*arr[j]+fun(i,j-1,1-f));
    }else{
        kk=1;
        return dp[i][j][f]=max(kk*arr[i]+fun(i+1,j,1-f),kk*arr[j]+fun(i,j-1,1-f));
    }
    
    return dp[i][j][f]=max(kk*arr[i]+fun(i+1,j,1-f),kk*arr[j]+fun(i,j-1,1-f));
    
    // if(k==0) return 0;
    
    // if(dp[k]!=-1)return dp[k];
    // int ans =0;
    
    // for(int i=0;i<n;i++){
    //     if(arr[i]<=k)ans|=(!fun(k-arr[i]));
    // }
    // // cout<<k<<" "<<ans<<endl;
    // return dp[k]=ans;
    
}

int main(){
    
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i+1];
    
    memset(dp,-1,sizeof(dp));    

    cout<<fun(1,n,0)<<endl;
    return 0;
}