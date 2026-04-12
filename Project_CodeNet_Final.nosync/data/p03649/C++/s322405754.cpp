#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
ll A[50];
int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  ll ans=0;
  while(1){
    sort(A,A+N);
    if(A[N-1]<N)break;

    //    cout<<ans<<' ';
    //    for(int i=0;i<N;i++)cout<<A[i]<<' ';
    //    cout<<endl;
    
    if(A[N-1]<N*2){
      A[N-1]-=N;
      for(int i=0;i<N-1;i++)A[i]++;
      ans++;
      continue;
    }
    
    
    ll tmp=0;
    for(int i=0;i<N;i++){
      if(A[i]<N)continue;
      ll v=A[i]/N;
      tmp+=v;
      A[i]-=v*N;
      A[i]-=v;
    }
    for(int i=0;i<N;i++)A[i]+=tmp;
    ans+=tmp;
  }
  cout<<ans<<endl;
  return 0;
}
