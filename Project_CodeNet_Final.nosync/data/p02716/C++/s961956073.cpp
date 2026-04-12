#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  long long N;
  cin>>N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin>>A.at(i);
  }
  long long dp[200010][3];
  if(N%2==1){
    for(long long i=0;i<N;i++){
      if(i==0){dp[i][1]=A.at(0);}
      else if(i==1){dp[i][1]=max(A.at(0),A.at(1));}
      else{
        if(i%2==0){
          dp[i][0]=max(dp[i-2][0]+A.at(i),dp[i-1][1]);
          dp[i][1]=dp[i-2][1]+A.at(i);
        }
        else{
          dp[i][0]=max(dp[i-2][0]+A.at(i),dp[i-1][0]);
          dp[i][1]=max(dp[i-2][1]+A.at(i),dp[i-1][1]);
        }
      }
    }
    cout<<dp[N-1][0]<<endl;
  }
  else{
    for(int i=0;i<N;i++){
      if(i==0){dp[i][1]=A.at(0);}
      else if(i==1){dp[i][0]=max(A.at(0),A.at(1));}
      else{
        if(i%2==0){
          dp[i][0]=max(dp[i-2][0]+A.at(i),dp[i-1][0]);
          dp[i][1]=dp[i-2][1]+A.at(i);
        }
        else{
          dp[i][0]=max(dp[i-2][0]+A.at(i),dp[i-1][1]);
        }
      }
    }
    cout<<dp[N-1][0]<<endl;
  }
}