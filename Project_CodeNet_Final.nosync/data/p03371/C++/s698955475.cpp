#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define INF 10000000
using ll = long long ;
ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
template< int id > struct CompTupleBy
{
  template<class T> 
  bool operator()( const T& a, const T& b ) const {
    return std::get<id>(a) < std::get<id>(b);
  }
};

using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >>c >> x >> y;
    ll ans = 100000000000000000;
    for (int i=0;i<=100000;i++){
        ll tmp = i*2*c + a * max(0,x-i) + b*max(0,y-i);
        ans = min(ans,tmp);
    }
    cout << ans << endl;
}
