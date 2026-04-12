#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,X;
  cin>>N>>X;
  vector<int> A(50),B(50);
  A[0]=1;B[0]=1;
  for(int i=1;i<50;i++)
    A[i]=A[i-1]*2+3,B[i]=B[i-1]*2+1;
  int ans=0;
  for(int i=N-1;i>=0;i--){
    if(X>A[i]+1)
      ans++;
    ans+=X/(A[i]+1)*B[i];
    X=X%(A[i]+1)-1;
    if(X<=0)
      break;
  }
  cout<<ans<<endl;
}