#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;

int main(){
ll N;
  cin>>N;
  ll A[N],sum[N];
  ll summod=0;
  for(ll i=0;i<N;i++){
  cin>>A[i];
  }

  for(ll i=0;i<N;i++){
    summod=summod+A[N-1-i];
    summod=summod%(1000000007);
    sum[N-2-i]=summod;
  }
  ll ans=0;
  for(ll i=0;i<N-1;i++){
    ans=ans+A[i]*sum[i];
    ans=ans%(1000000007);
    //cout<<ans<<endl;
  }
  
  
  cout<<ans<<endl;
  
}
