/*{{{*/
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>

typedef long long ll;

#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i,a,b) for(ll i=b-1;i>=a;i--)

#define DEBUG(x) cout<<#x<<": "<<x<<endl

using namespace std;
/*}}}*/

int main() {
  ll n;
  cin >> n;
  ll bf = 0;
  ll ans = 0;
  ll nx = 0;
  ll ma = 0;
  REP(i,n){
    cin >> nx;
    if(nx>=ma) ans++;
    ma = max(ma,nx);
  }
  cout << ans<< endl;
  return 0;
}
