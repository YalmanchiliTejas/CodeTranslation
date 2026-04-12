#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=1000010;
const ll mod=1e9+7;


int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  if(n%2==0){
    ll ans = 0;
    rep(i,n/2){
      ans -= a[i];
      ans += a[i+n/2];
    }
    ans = ans*2 + a[n/2-1] - a[n/2];
    cout << ans << endl; return 0;
  }

  ll ans1 = 0;
  rep(i,n){
    if(i<n/2){
      ans1 -= 2*a[i];
    } else {
      ans1 += 2*a[i];
    }
  }
    ans1 -= a[n/2] + a[n/2+1];

  ll ans2 = 0;
  rep(i,n){
    if(i<n/2+1){
      ans2 -= 2*a[i];
    } else {
      ans2 += 2*a[i];
    }
  }
    ans2 += a[n/2] + a[n/2-1];
  ll ans = max(ans1, ans2);
  cout << ans << endl;

  return 0;
}