#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 111111

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

int main() {
  ll a, b, c, x, y ;
  ll ans = 0LL ;

  cin >> a >> b >> c >> x >> y ;

  int temp = min(x, y) ;
  x-=temp , y-=temp ;

  if(a+b >= c*2){
    ans = temp*c*2 ;
  }
  else{
    ans = temp*(a+b) ;
  }

  if(!x){
    if(b>=c*2)
      ans+=(y*c*2) ;
    else
      ans+=(y*b) ;
  }
  else {
    if(a>=c*2)
      ans+=(x*c*2);
    else ans+=(x*a) ;
  }
  cout << ans << endl ;
	
  return 0 ;
}