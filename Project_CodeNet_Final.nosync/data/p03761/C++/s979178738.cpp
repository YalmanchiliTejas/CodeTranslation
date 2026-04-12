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
  ll n;
  cin >> n;
  vector<map<char,ll>> count(n);
  for(ll i=0;i<n;i++) {
    string s;
    cin >> s;
    for(ll j=0;j<s.size();j++) {
      count[i][s[j]]++;
    }
  }
  map<char,ll> ans;
  for(ll i=0;i<'z'-'a'+1;i++) {
    ll num=inf;
    for(ll j=0;j<n;j++) {
      num=min(num,count[j]['a'+i]);
    }
    ans['a'+i]=num;
  }
  for(ll i=0;i<'z'-'a'+1;i++) {
    for(ll j=0;j<ans['a'+i];j++) {
      cout << char('a'+i);
    }
  }
  cout << endl;
}