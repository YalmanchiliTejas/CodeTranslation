#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int A, B, C, X, Y;


int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B >> C >> X >> Y;

  int ans1 = A*X+ B*Y;

  int s,t, d,e;
  if (X>Y){
    s=X; t=Y;
    d = A; e = B; 
  } else{
    s=Y; t=X;
    d = B; e = A;
  }
  int ans2 = C*2*t + d*(s-t);
  int ans = min(ans1, ans2);
  int ans3 = C*2*s; 
  ans =  min(ans,ans3);
  cout << ans << endl;
  return 0;
}