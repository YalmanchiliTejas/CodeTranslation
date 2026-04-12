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
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin>>N;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  ll sum=0;
  ll ans=0;
  rep(i,N){
    ans+=A[i]*sum%MOD;
    ans%=MOD;
    sum+=A[i];
    sum%=MOD;
  }

  cout<<ans<<endl;

  return 0;
}
