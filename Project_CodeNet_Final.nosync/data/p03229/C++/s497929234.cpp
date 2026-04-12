#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  long long A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A,A+N);
  long long ans=0;
  long long ansmax=0;
  
  if(N%2 == 1){
    for(int i=0;i<=N/2-1;i++){
      ans+=A[N-1-i]*2;
    }
    ans-=A[N-1-N/2];
    ans-=A[N-2-N/2];
    for(int i=0;i<=N/2-2;i++){
      ans-=A[i]*2;
    }
    //cout<<"ans1"<<ans<<endl;
    ansmax=ans;
    ans=0;
    
    for(int i=0;i<=N/2-2;i++){
      ans+=A[N-1-i]*2;
    }
    ans+=A[N-1-N/2];
    ans+=A[N-N/2];
    for(int i=0;i<=N/2-1;i++){
      ans-=A[i]*2;
    }
    //cout<<"ans2"<<ans<<endl;
    ansmax=max(ans,ansmax);
  }
  else{
    ans=0;
    for(int i=0;i<N/2-1;i++){
      ans+=A[N-1-i]*2;
    }
    //cout<<"#"<<ans<<endl;
    ans+=A[N-N/2];
    ans-=A[N-N/2-1];
    for(int i=0;i<N/2-1;i++){
      ans-=A[i]*2;
    }
    //cout<<"ans3"<<ans<<endl;
    ansmax=max(ans,ansmax);
  }
  
  
  cout<<ansmax<<endl;
  return 0;
}
