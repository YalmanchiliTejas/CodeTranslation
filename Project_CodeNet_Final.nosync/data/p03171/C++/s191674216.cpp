#include<bits/stdc++.h>
using namespace std;
int main(){
long long n;
cin>>n;
vector<long long> v(n+1);
long long sum=0;
for(int i=1;i<=n;i++){
    cin>>v[i];
    sum+=v[i];
}
long long dp[n+10][n+10];
memset(dp,0,sizeof(dp));

for(int i=1;i<=n;i++){
     dp[i][i]=v[i];
     if(i+1<=n)
            dp[i][i+1]=max(v[i],v[i+1]);
}

for(int len=3;len<=n;len++){
      int i=1,j=len;
      while(j<=n){
               dp[i][j]=max(v[i]+min(dp[i+2][j],dp[i+1][j-1]),v[j]+min(dp[i][j-2],dp[i+1][j-1]));

        j++;
        i++;
      }

}


     cout<<2*dp[1][n]-sum<<"\n";

}
