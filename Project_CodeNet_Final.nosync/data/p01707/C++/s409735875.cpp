#include<iostream>
#include<vector>

using namespace std;

vector<int> mul(vector<int> a,vector<int> b){
  vector<int> c(a.size());
  for(int i=0;i<c.size();i++){
    for(int j=0;j<=i;j++){
      c[i]=(c[i]+a[j]*1LL*b[i-j])%1000000007;
    }
  }
  return c;
}

int main(){
  for(long long N,D,X;cin>>N>>D>>X,N|D|X;){
    vector<int> dp(N+1);
    dp[0]=1;
    vector<int> po2(N+1);
    for(int i=0;i<min(X,N+1);i++){
      po2[i]=1;
    }
    for(long long i=1;i<=D;i<<=1){
      if(D&i){
	dp=mul(dp,po2);
      }
      po2=mul(po2,po2);
    }
    cout<<dp[N]<<endl;
  }
}