#include "bits/stdc++.h"

using namespace std;

#define ll  long long
#define vi  vector<int>
#define pi  pair<int,int>
#define mp  make_pair
#define pb  push_back
#define MOD 1e9 + 7
#define PAI  3.1415
#define all(x) (x).begin(),(x).end()
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
#define pr(x) cout << x << endl
#define Endl endl
#define rep(i,n) for(int i = 0 ; i < n; i++)

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int inf = 99999999;
const ll linf = 1LL << 62;

ll gcd(ll a,ll b){
  if(a < b)swap(a , b);
  if(a % b == 0) return b;
  else gcd(b, a%b);
}

ll lcm(ll a,ll b){
  if(a < b)swap(a , b);
  return (a/gcd(a , b))*b;
}

int main(){

  int a,b,c,x,y;
  ll ans = 0;
  cin >> a >> b >> c >> x >> y;

  if(x == 0)ans = min(b,2*c)*y;
  else if(y == 0) ans = min(a,2*c)*x;
  else {
    if(a+b < 2*c)ans = a*x + b*y;
    else{
      ans = 2*c*min(x,y);
      if(x > y){
        x -= y;
        if(a > 2*c)ans += 2*c*x;
        else ans+= a*x;
      }
      else{
        y -= x;
        if(b > 2*c)ans += 2*c*y;
        else ans += b*y;
      }
    }
  }

  pr(ans);

  return 0;
}

