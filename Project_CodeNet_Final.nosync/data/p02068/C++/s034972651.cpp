#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int N;
vector<ll> A;

map<ll,ll> mp;

void factorize(ll X,ll V){
  for(ll i=2;i*i<=X;i++){
    if(X%i==0){
      while(X%i==0) X/=i;
      mp[i]+=V;
    }
  }

  if(X!=1) mp[X]+=V;
}

int main(){
  cin>>N;
  A.resize(N);
  for(int i=0;i<N;i++) cin>>A[i];

  for(int i=0;i<N;i++) factorize(A[i],A[i]);

  ll ans=0;
  for(auto m:mp){
    ans=max(ans,m.second);
  }
  cout<<ans<<endl;

  return 0;
}

