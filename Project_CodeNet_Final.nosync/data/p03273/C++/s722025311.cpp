#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const ll inf=1e18;

int main() {
  ll h,w;
  cin >> h >> w;
  vector<string> s(h);
  for(ll i=0;i<h;i++) {
    cin >> s[i];
  }
  set<ll> nh;
  for(ll i=0;i<h;i++) {
    bool flag=true;
    for(ll j=0;j<w;j++) {
      if(s[i][j]=='#') {
        flag=false;
        break;
      }
    }
    if(flag) {
      nh.insert(i);
    }
  }

  set<ll> nw;
  for(ll i=0;i<w;i++) {
    bool flag=true;
    for(ll j=0;j<h;j++) {
      if(s[j][i]=='#') {
        flag=false;
        break;
      }
    }
    if(flag) {
      nw.insert(i);
    }
  }

  for(ll i=0;i<h;i++) {
    if(nh.count(i)) continue;
    for(ll j=0;j<w;j++) {
      if(nw.count(j)) continue;
      cout << s[i][j];
    }
    cout << endl;
  }
}