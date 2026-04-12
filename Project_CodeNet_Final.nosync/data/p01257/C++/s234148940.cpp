#include <iostream>
#define N_MAX 10
#define M_MAX 100001
#define f first
#define s second
using namespace std;
typedef pair<bool,int> P;
int Binary_Search();
bool DP_Check(int);
int N,M,c[N_MAX];

int main(){
  while(1){
    cin>>N>>M;
    if(!N&&!M) break;
    for(int i=0;i<N;i++) cin>>c[i];
    cout<<Binary_Search()<<endl;
  }
  return 0;
}

int Binary_Search(){
  int l=0,r=M+1,m;
  while(l<r){
    m=(l+r)/2;
    DP_Check(m)?r=m:l=m+1;
  }
  return l;
}

bool DP_Check(int k){
  P dp[M+1];
  for(int i=0;i<=M;i++) dp[i].f=false,dp[i].s=0; 
  dp[0].f=true;
  for(int i=0;i<N;i++){
    for(int j=c[i];j<=M;j++){
      if(dp[j].f) continue;
      if(dp[j-c[i]].f&&dp[j-c[i]].s</*=*/k){
	//	if(dp[j-c[i]].s==k) break;
	dp[j].f=true;
	dp[j].s=dp[j-c[i]].s+1;
      }
    }
    for(int j=0;j<=M;j++) dp[j].s=0;
  }
  if(dp[M].f==true) return true;
  return false;
}