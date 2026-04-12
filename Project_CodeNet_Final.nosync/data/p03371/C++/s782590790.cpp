#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repe(i,n) for (int i = 1; i <= (n); ++i)
#define reps(i,start,end,step) for (int i = start; i <= end; i+=step)
#define rep_bit(n) for (int bit = 0; bit < (1 << n); ++bit)
using namespace std;
typedef long long ll;
typedef string str;
const ll INF = 1e18;
const int MX = 2005;
const double pi = 3.141592653589793238;

int main() {

  ll A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = 0;
  if(A+B<=2*C){
    ans = A*X+B*Y;
  }
  else{
    if(X<Y) ans = 2*C*X + min(B,2*C)*(Y-X);
    else if(X>Y) ans = 2*C*Y + min(A,2*C)*(X-Y);
    else ans = 2*C*X;
  }
  cout << ans << endl;
  return 0;
}