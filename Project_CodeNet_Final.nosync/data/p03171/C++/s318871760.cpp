#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)

ll n,a[3010],dp[3010][3010]={};

int main(){
  cin>>n;
  fr(i,n) cin>>a[i];
  fr(i,n){
    fr(j,n-i){
      ll k=j+i;
      if(i==0){dp[j][k]=a[j];continue;}
      dp[j][k]=max(a[j]-dp[j+1][k],a[k]-dp[j][k-1]);
    }
  }
  cout<<dp[0][n-1]<<endl;
}