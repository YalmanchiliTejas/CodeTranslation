#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define endl "\n"
using ll=long long;
using ld=long double;
using namespace std;
const ll mod= 1e9+7;
const ll INF = 1LL<<40;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int main(){
  ll n,k,ans=0;
  string s;
  cin>>s;
  rep(i,0,3){
    if(s[i]=='A')ans++;
    else if(s[i]=='B')ans--;
  }
  if(ans==3||ans==-3)cout<<"No";
  else cout<<"Yes";
}