#include <bits/stdc++.h>
using namespace std;
#define REP(i,N) for(i=0;i<N;i++)
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
  typedef long long ll;
  typedef pair<int,int> PII;
  typedef pair<char,char> PCC;
  typedef pair<ll,ll> PLL;
  typedef pair<char,int> PCI;
  typedef pair<int,char> PIC;
  typedef pair<ll,int> PLI;
  typedef pair<int,ll> PIL; 
  typedef pair<ll,char> PLC; 
  typedef pair<char,ll> PCL; 

int main(void){
  int A,B,C,X,Y;cin >> A >> B >> C >> X >> Y;
  ll ans = 0;
  if(A+B>2*C){
    int m = min(X,Y);
    X -= m;
    Y -= m;
    ans = 2ll*m*C;
  }
  if(A>2*C) ans += (ll) 2*X*C;
  else ans += (ll) X*A;
  if(B>2*C) ans += (ll) 2*Y*C;
  else ans += (ll) Y*B;
  cout << ans << endl;
  return 0;
}
