#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int N;

int a[3001];

long long dp[3001][3001];

long long ans(int head,int tail,bool judge){

  if(dp[head][tail]!=-1){
    return dp[head][tail];
  }
	     
  if(head>tail){
    return 0;
  }
  
  if(judge){
    return dp[head][tail]=max(ans(head,tail-1,!judge)+a[tail],ans(head+1,tail,!judge)+a[head]);
  }
  else{
    return dp[head][tail]=min(ans(head,tail-1,!judge)-a[tail],ans(head+1,tail,!judge)-a[head]);
  }    
}


int main(){

  cin.tie(0);     // cout と cin の同期を切る
  ios::sync_with_stdio(false);  /* cの stdioストリーム (printfとか)と*/

  memset(dp,-1,sizeof(dp));
  
  cin>>N;

  for(int i=0;i<N;i++){

    cin>>a[i];

  }

  cout<<ans(0,N-1,1)<<endl;
  
  
  return 0;

}
