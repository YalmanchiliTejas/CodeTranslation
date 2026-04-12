#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define sz(x) ll(x.size())
using namespace std;

int main() {
  ll n,ans=1,hmax,h;
  cin >> n >> hmax;
  rep(i,n-1){
  	cin >> h;
    if(hmax<=h){
    	ans++;
    	hmax=max(h,hmax);
    }
  }
  cout << ans << endl;
}
