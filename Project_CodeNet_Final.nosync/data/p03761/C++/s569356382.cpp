#include <bits/stdc++.h>
using namespace std;typedef long long ll;typedef string str;
typedef vector<str> vst;
typedef vector<ll> vll;
// ll gcd(ll a, ll b){if (b==0){return a;}return gcd(b, a%b);}
// for (ll i=0;i<n;i++) {
// sort(.begin(),.end());
int main(){
  ll n,ans=1;
  cin>>n;
  vst s(n);
  vector<vll> c(n,vector<ll>(26,0));
  for (ll i=0;i<n;i++) {
    cin>>s[i];
    for (ll j=0;j<s[i].size();j++) {
      c[i][s[i][j]-'a']++;
    }
    if (i==0) continue;
    for (ll j=0;j<26;j++) {
      if (c[i][j]>=c[i-1][j]) {
        c[i][j]=c[i-1][j];
      }
    }
  }
  
  for (ll i=0;i<26;i++) {
    for (ll j=0;j<c[n-1][i];j++) {
      cout<<char(i+97);
    }
  }
  cout<<endl;
}