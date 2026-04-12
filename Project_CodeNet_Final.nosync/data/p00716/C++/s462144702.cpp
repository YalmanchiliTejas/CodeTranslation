#include<iostream>
#include<algorithm>
using namespace std;
#define FOR(i,b,n) for(int i = (b) ; i < (n) ; ++i)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
int main(){
  ll  money , year , n[100], Q , ans;
  int q;
  long double ss;
  cin >> q;
  while( q-- ){
    ans = 0;
    cin >> money >> year >> Q;
    rep(i,Q){
      ll n,bad;
      cin >> n >> ss >> bad;
      if(n == 0){
        ll a = money;
        ll now = 0;
        rep(j,year){
          now += ss * a;
          a -= bad;
        }
        ans = max(ans,a+now);
      } else{
        ll a = money;
        rep(j,year) a = a + ss * a - bad;
        ans = max(ans,a);
      }
    }
    cout << ans << endl;
  }
}