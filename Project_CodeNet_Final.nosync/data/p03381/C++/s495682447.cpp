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
#define DIV ll(1e9+7)
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
//const double PI = M_PI;  
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}
// IT 5000兆　欲しい
/* Coding space */
int main(){
  vi x;
  vi tx;
  ll n; cin >> n;
  rep(i,n){int in; cin >> in; x.pb(in);}
  
  tx = x;
  sort(ALL(x));
  
  rep(i,n){
    int d = lower_bound(ALL(x),tx[i]) - x.begin();
    if(d >= n/2) cout << x[n/2 -1] << endl;
    else cout << x[n/2] << endl;
  }
  
}