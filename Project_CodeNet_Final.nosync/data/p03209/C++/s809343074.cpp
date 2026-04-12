#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

long long int B[55],P[55],S[55];

long long int sol(long long int n,long long int x){
  //if(n==0 && x==1) return 1;
  if(x<=n) return 0;
  //printf(":::%lld %lld\n",n,x);


  if(x==((S[n])/2)) return P[n-1];
  if(x==((S[n]+1)/2)) return P[n-1]+1;
  if(x==S[n]) return P[n];

  if(x>(S[n]+1)/2 && x<=S[n]){
    return P[n-1] +1 +sol(n-1,x-S[n-1]-2);
  }
  else{
    return sol(n-1,x-1);
  }
}

int main(){
  long long int n,x;
  cin>>n>>x;
  B[0]=0;
  P[0]=1;
  S[0]=1;
  for(int i=1;i<=n+1;i++){
    B[i]=B[i-1]*2 + 2;
    P[i]=P[i-1]*2 + 1;
    S[i]=B[i]+P[i];
    //printf(": %lld %lld %lld\n",B[i],P[i],S[i]);
  }
  cout<<sol(n,x)<<endl;

  return 0;
}