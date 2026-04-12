#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll h,w;
  cin >> h >> w;
  vector<string> a(h);
  for(ll i=0;i<h;i++)  cin >> a[i];
  ll count=0;
  for(ll i=0;i<h;i++) for(ll j=0;j<w;j++) if(a[i][j]=='#') count++;
  if(count==h+w-1) {
    cout << "Possible" << endl;
  }
  else {
    cout << "Impossible" << endl;
  }
}