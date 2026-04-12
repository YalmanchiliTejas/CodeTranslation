#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int main(){
  int N; cin>>N;
  ll A[N]; rep(i,N) cin>>A[i];
  sort(A,A+N);
  ll ans=0;
  while(A[N-1]>2*N){
    ll k=max(1LL,(A[N-1]-2*N)/N);
    A[N-1]-=k*N;
    rep(i,N-1) A[i]+=k;
    sort(A,A+N);
    ans+=k;
  }
  while(A[N-1]>=N){
    A[N-1]-=N;
    rep(i,N-1) A[i]++;
    sort(A,A+N);
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}
