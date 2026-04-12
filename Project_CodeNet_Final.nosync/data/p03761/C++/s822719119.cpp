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
  ll n;
  cin >> n;
  map<char,ll> ans;
  for(ll i=0;i<n;i++) {
    string tmp;
    cin >> tmp;
    map<char,ll> cnt;
    if(i==0) {
      for(ll j=0;j<tmp.size();j++) {
        ans[tmp[j]]++;
      }
    }
    else {
      for(ll j=0;j<tmp.size();j++) {
        cnt[tmp[j]]++;
      }
      for(auto p:ans) {
        ans[p.first]=min(p.second,cnt[p.first]);
      }
    }
  }
  for(auto p:ans) {
    ll num=p.second;
    while(num-->0) {
      cout << p.first;
    }
  }
  cout << endl;
}