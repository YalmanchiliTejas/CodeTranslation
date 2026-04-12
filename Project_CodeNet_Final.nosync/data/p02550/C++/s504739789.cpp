#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
#include <functional>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  ll N,X,M;
  cin>>N>>X>>M;
  VL A(M,-1),Y(min(M,N));
  ll tmp=X;
  ll P=min(N,M)-1;
  if(X==0){
    cout<<0<<endl;
    return 0;
  }
  rep(i,min(N,M)){
    if(A[tmp]>=0){
      P=i;
      break;
    }else{
      Y[i]=tmp;
      A[tmp]=i;
      tmp=tmp*tmp%M;
    }
  }
  ll ans=0;
  rep(i,P+1) ans+=Y[i];
  ll ans2=0;
  if(P+1!=N){
    rep(i,P-A[tmp]) ans2+=Y[A[tmp]+i];
    ans2=ans2*((N-P)/(P-A[tmp]));
    ans+=ans2;
    rep(i,(N-P)%(P-A[tmp])) ans+=Y[A[tmp]+i];
  }
  cout<<ans<<endl;
}


