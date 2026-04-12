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

int main(){
  cin>>N;
  A.resize(N);
  rep(i,N) cin>>A[i];
  
  ll ans=0;
  while(1){
      vector<ll> num(N,0);
      ll sum=0;
      for(int i=0;i<N;i++){
          num[i]+=A[i]/N;
          sum+=num[i];
      }
      if(sum==0) break;

      ans+=sum;
      for(int i=0;i<N;i++){
          A[i]%=N;
          A[i]+=(sum-num[i]);
      }
  }
  cout<<ans<<endl;

  return 0;
}
