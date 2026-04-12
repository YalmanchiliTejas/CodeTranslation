#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const int MOD = 1000000007;

int main(){
  ll n;cin>>n;
  vector<string> s(n);
  vvll alpha(n,vll(30,0));
  vll ans(30,0);
  rep(i,0,n){
    cin>>s[i];
    rep(j,0,s[i].size()){
      ll x=s[i][j]-'a';
      alpha[i][x]++;
    }
  }
  rep(i,0,30){
    ll tmp=INF;
    rep(j,0,n){
      tmp=min(tmp,alpha[j][i]);
    }
    ans[i]=tmp;
    rep(k,0,ans[i]){
      char x=i+'a';
      cout<<x;
    }
  }
  cout<<endl;

}