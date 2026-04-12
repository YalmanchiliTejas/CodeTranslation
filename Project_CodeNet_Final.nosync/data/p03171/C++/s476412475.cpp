#include<iostream>
using namespace std;
long long int dp[3001][3001];
long long int v[3001][3001]; 
long long int a[3001];
long long int solve(int l, int r){
    if(v[l][r]==1){
        return dp[l][r];
    }
    v[l][r]=1;
    if(l==r){
        dp[l][r]=a[l];
        return a[l];
    }
    long long int ret;
    ret=max(a[l]-solve(l+1,r),a[r]-solve(l,r-1));
    dp[l][r]=ret;
    return ret;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<3001; i++){
        for(int j=0; j<3001; j++){
            v[i][j]=0;
        }
    }
    cout<<solve(0,n-1)<<endl;
    return 0;
}

