#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;
template<class T> using ttt = tuple<T,T>;
using tii = tuple<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define DIV int(1e9+7)
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const long double eps = 1e-10;
//const double PI = M_PI; 
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}

/* Coding Space. */
// レベルLの下からのxに何個あるのか
ll f(ll n, ll x){
  //cerr << n << " " << x << endl;
  if(n == 0)  return (x <= 0)?0:1;
  if(pow(2, n+2, LLINF)/2 - 1 == x){return 1 + f(n-1,x-2);}
  else if(pow(2, n+2, LLINF)/2 - 1 > x){return f(n-1,x-1);}
  else if(pow(2, n+2, LLINF)/2 - 1 < x){return 1 + (pow(2, n, LLINF) - 1) + f(n-1, x - (pow(2, n + 1, LLINF) - 3) - 2);}
  return -LLINF;
}
int main(){
  ll n,x; cin >> n >> x;
  cout << f(n,x) << endl;
}