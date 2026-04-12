#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,X,M;
  cin>>N>>X>>M;
  int n=X,m;
  vector<int> A(M,-1);
  for(int i=0;i<N;i++){
    if(A[n]!=-1){
      m=i-A[n];
      break;
    }else A[n]=i;
    n=n*n%M;
    if(i==N-1){
      int ans=0;
      for(int i=0;i<N;i++){
        ans+=X;
        X=X*X%M;
      }
      cout<<ans<<endl;
      return 0;
    }
  }
  int ans=0;
  for(int i=0;i<A[n];i++){
    ans+=X;
    X=X*X%M;
  }
  int sum=0;
  for(int i=0;i<(N-A[n])%m;i++){
    sum+=X;
    ans+=X;
    X=X*X%M;
  }
  for(int i=(N-A[n])%m;i<m;i++){
    sum+=X;
    X=X*X%M;
  }
  cout<<ans+(N-A[n])/m*sum<<endl;
}