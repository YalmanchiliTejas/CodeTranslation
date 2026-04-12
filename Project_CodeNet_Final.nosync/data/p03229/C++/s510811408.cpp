#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  sort(rng(A));
  ll ans=0;
  if(N%2==0){
    ans=-A[N/2-1]+A[N/2];
    for(int i=0;i<N/2-1;i++)ans-=2*A[i];
    for(int i=N/2+1;i<N;i++)ans+=2*A[i];
  }
  else{
    ll ans1=-A[N/2-1]-A[N/2];
    for(int i=0;i<N/2-1;i++)ans1-=2*A[i];
    for(int i=N/2+1;i<N;i++)ans1+=2*A[i];
    ll ans2=A[N/2]+A[N/2+1];
    for(int i=0;i<N/2;i++)ans2-=2*A[i];
    for(int i=N/2+2;i<N;i++)ans2+=2*A[i];
    ans=max(ans1,ans2);
  }
  cout<<ans<<endl;

  return 0;
}
