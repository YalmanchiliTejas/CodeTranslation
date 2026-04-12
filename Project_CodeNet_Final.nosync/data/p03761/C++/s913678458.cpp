#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
using ll=long long;
using ld=long double;
using namespace std;
const ll mod=1e9+7;
ll p[1000][1000];
ll m[1000];
int main(){
  ll n,t,tmp=0;
  cin>>n;
  string s[220];
  rep(i,0,n){cin>>s[i];}
  rep(i,0,30)m[i]=100;
  rep(i,0,n){
    rep(j,0,s[i].length())p[s[i][j]-0x61][i]++;
  } 
  rep(i,0,30){
    rep(j,0,n){
      m[i]=min(m[i],p[i][j]);
    }
  }
  rep(i,0,30){
    rep(j,0,m[i])cout<<char(i+0x61);
  }
}