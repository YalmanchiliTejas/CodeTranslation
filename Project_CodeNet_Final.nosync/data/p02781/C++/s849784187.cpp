#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
ll dp[105][2][5]={0};
int main(){
  string N;
  cin>>N;
  ll K;
  cin>>K;
  dp[0][0][0]=1;
  int nl=N.length();
  for(int i=0;i<nl;i++){
    int n=(int)(N[i]-'0');
    for(int k=0;k<=K;k++){
      if(n==0){
        dp[i+1][0][k]+=dp[i][0][k];
        dp[i+1][1][k]+=dp[i][1][k];
        dp[i+1][1][k+1]+=dp[i][1][k]*9;
      }
      else{
        dp[i+1][1][k]+=dp[i][0][k];
        dp[i+1][1][k+1]+=(n-1)*dp[i][0][k];
        dp[i+1][0][k+1]+=dp[i][0][k];
        dp[i+1][1][k]+=dp[i][1][k];
        dp[i+1][1][k+1]+=dp[i][1][k]*9;
      }
    }
  }
  ll ans=0;
  ans+=dp[nl][0][K];
  ans+=dp[nl][1][K];
  cout<<ans<<endl;
}
