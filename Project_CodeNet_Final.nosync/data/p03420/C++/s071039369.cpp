#include <bits/stdc++.h>
using namespace std;
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define debug(x) cerr<<#x<<':'<<x<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto x:v)cerr<<x<<' ';cerr<<endl;
#define INF 1000000007
#define LINF 1000000000000000007
#define EPS 1e-9
typedef long long ll;


signed main(){
  ll N,K;
  ll ans = 0;
  cin >> N >> K;
  if(K == 0){
    cout << N*N << endl;
    return 0;
  }
  FOR(b,K+1,N+1){
    ll n = N/b;
    ans += (b-K)*n;
    ll mod = N%b;
    ans += max((ll)0,mod-K+1);
  }
  cout << ans << endl;
}
