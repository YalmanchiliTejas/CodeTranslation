#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF=1e18+1;
const int mod = 1000000007;

int main() {
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  C*=2;
  int ab=0;
  if(X==Y){ab=X;}
  else if(X>Y){ab=Y;}
  else{ab=X;}
  int ans=min({A*X+B*Y,(X-ab)*A+(Y-ab)*B+C*ab,C*max(X,Y)});
  cout<<ans<<endl;
  return 0;
}