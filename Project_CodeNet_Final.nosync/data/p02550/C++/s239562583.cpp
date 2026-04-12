#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<"\n"
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> tll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
template<class T> inline bool chmax(T& a, T b) { 
 if (a < b) { a = b; return true; } return false; 
}
template<class T> inline bool chmin(T& a, T b) {
 if (a > b) { a = b; return true; } return false; 
}
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,x,m;
  cin>>n>>x>>m;
  vll f(0);
  f.pb(x);
  set<ll> s;
  s.insert(x);
  ll cu=x;
  ll k= -1;
  rep(i,n){
      if(i==0) continue;
      cu*=cu;
      cu%=m;
      if(cu==0){
          break;
      }
      if(s.count(cu)){
          k=cu;
          break;
      }
      s.insert(cu);
      f.pb(cu);
  }
  ll ans=0;
  if(k==-1){
    rep(i,sz(f)){
        ans+=f[i];
    }
    COUT(ans);
  }
  else{
      ll ff,ss;
      ff=-1;ss=sz(f);
      rep(i,sz(f)){
          if(cu==f[i]){
              ff=i;
              break;
          }
      }
      rep(i,ff){
          ans+=f[i];
      }
      n-=ff;
      ll j=0;
      for(int i=ff;i<sz(f);i++){
          j+=f[i];
      }
      ans+=j*(n/(ss-ff));
      n%=(ss-ff);
      for(int i=ff;i<ff+n;i++){
          ans+=f[i];
      }
      COUT(ans);
  }
}
