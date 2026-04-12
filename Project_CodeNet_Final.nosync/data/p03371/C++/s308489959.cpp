#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  ll A,B,AB,X,Y;
  cin >> A >> B >> AB >> X >> Y;
  ll ans = 1e18;
  for(ll ab=0;ab<=max(X,Y)*2;ab++){
    ll preans;
    ll a = max((ll)0,X - ab/2);
    ll b = max((ll)0,Y - ab/2);
    preans = A*a+B*b+AB*ab;
    //cout << ab << " " << preans << endl;
    ans = min(ans,preans);
  }
  cout << ans << endl;
  return 0;
}
