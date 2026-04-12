#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll h,w;
  cin >> h >> w;
  vector<string> maze(h);
  for(ll i=0;i<h;i++) cin >> maze[i];
  set<ll> y,x;
  for(ll i=0;i<h;i++) {
    ll f=1;
    for(ll j=0;j<w;j++) {
      if(maze[i][j]=='#')f=0;
    }
    if(f) y.insert(i);
  }
  for(ll i=0;i<w;i++) {
    ll f=1;
    for(ll j=0;j<h;j++) {
      if(maze[j][i]=='#')f=0;
    }
    if(f) x.insert(i);
  }
  for(ll i=0;i<h;i++) {
    if(y.count(i)) continue;
    for(ll j=0;j<w;j++) {
      if(x.count(j)) continue;
      cout << maze[i][j];
    }
    cout << endl;
  }
}