#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n;
  string s;
  ll k;
  cin >> n >> s >> k;
  char c=s[k-1];
  for(ll i=0;i<n;i++) {
    if(s[i]!=c) {
      s[i]='*';
    }
  }
  cout << s << endl;
}