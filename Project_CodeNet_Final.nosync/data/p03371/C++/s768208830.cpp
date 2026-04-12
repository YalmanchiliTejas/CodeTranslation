#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(obj) (obj).begin(),(obj).end()
#define debug(x) cerr << #x << ": " << endl
#define rep(i,n) for(int i=0; (i)<(n); ++(i))
#define rrep(i,n) for(int i=(n); (i)>=0; --(i))
#define reps(i,s,n) for(int i=(s); (i)<(n); ++(i))
#define maxi(v) distance(v.begin(), max_element(v.begin(), v.end()))
#define mini(v) distance(v.begin(), min_element(v.begin(), v.end()))
#define maxemt(v) *max_element(v.begin(), v.end())
#define minemt(v) *min_element(v.begin(), v.end())
#define lb(v,x) v[lower_bound(v.begin(), v.end(), x) - v.begin()]
#define ub(v,x) v[upper_bound(v.begin(), v.end(), x) - v.begin()]
template<class T> inline bool print(T& x){ cout << x << endl; return true; }
template<class T> inline bool print_(T& x){ cout << x << " "; return true; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll x, ll y){
  if(y==0) return x;
  else return gcd(y, x%y);
  }
ll lcm(ll x, ll y){
  return x / gcd(x,y) * y;
}
const int INF = 1e9;
const ll llINF = 1LL<<60;
const int MOD = 1e9+7;
const double EPS = 1e-9;
int main(){
  int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  int ans = a*x + b*y;
  if(a+b > c*2){
    ans = min(x,y)*c*2;
    if(x-y>0 && a<=c*2) ans += (x-y)*a;
    else if(x-y>0 && a>c*2) ans += (x-y)*c*2;
    else if(x-y<0 && b<=c*2) ans += (y-x)*b;
    else if(x-y<0 && b>c*2) ans += (y-x)*c*2;
  }
  cout << ans;
  
  return 0;
}
