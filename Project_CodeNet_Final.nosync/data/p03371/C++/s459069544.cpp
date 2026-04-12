#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int N=max(X,Y);
  int ans=1e12+7;
  rep(i,N+1){
    int Amo=i*2*C;
    if(X-i>0)Amo+=(X-i)*A;
    if(Y-i>0)Amo+=(Y-i)*B;
    ans=min(ans,Amo);
  }
  cout<<ans<<endl;
}