#include <bits/stdc++.h>
using namespace std;

long long dp[3001][3001];
long long rec(int i,int j,vector<int> &a){
    if(i>j){
        dp[i][j]=0;
    }
    else if(i==j){
        dp[i][j]=a[i];
    }
    else if(j-i==1){
        dp[i][j]=max(a[i],a[j]);
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    long long x=a[i]+min(rec(i+2,j,a),rec(i+1,j-1,a));
    long long y=a[j]+min(rec(i,j-2,a),rec(i+1,j-1,a));
    dp[i][j]=max(x,y);
    return dp[i][j];
}
int main() {
    //code
    int n;
        cin>>n;
        for(int i=0;i<3001;i++){
            for(int j=0;j<3001;j++){
                dp[i][j]=-1;
            }
        }
        vector<int> a(n);
  long long sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
          sum+=(long long)a[i];
        }
        
        long long ans=rec(0,n-1,a);
  ans=(long long)(2*ans-(long long)sum);
        cout<<ans<<endl;
    return 0;
}