#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) begin(a),end(a)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1e+9;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
ll gcd(ll a, ll b){
  if (b==0) return a;
  else return gcd(b,a%b);
}
int cans(bool f){
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}


int fac(int num) {
  if(num==1) return 1;
  else return num*fac(num-1);
}





int main() {
  ll a,b,c,x,y;
  ll ans = 0;
  cin >> a >> b >> c >> x >> y;
  if(a+b >=2*c) {
    ans += 2*c*min(x,y);
    ll m = min(x,y);
    x-=m;
    y-=m;
    if(y == 0 && a >= 2*c) ans += 2*x*c,x=0;
    else if(x == 0 && b >= 2*c) ans += 2*y*c,y=0;
    ans += x*a + y*b;
  }
  else {
    ans += x*a + y*b;
  }


  cout << ans << endl;
  return 0;
}
