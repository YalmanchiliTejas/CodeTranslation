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
  string s;
  cin >> s;
  string ac="AC";
  ll n=s.size();
  ll f=0;
  for(ll i=0;i<n-1;i++) {
    if(s.substr(i,2)==ac) f=1;
  }
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
}