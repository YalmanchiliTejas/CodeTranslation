#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
ll powmod(ll n, ll k, ll m) {
ll r=1;
 for(; k>0; k >>=1) {
   if(k&1) r=(r*n)%m;
   n=(n*n)%m;
 }
  return r;
}

ll fact(ll n) {
ll a=1;
rep(i,n) {
a=a*(n-i);
}
return a;
}

ll pow(ll a, ll b) {
ll x=1;
rep(i,b) {
x=x*a;
}
return x;
}
ll P[9]={0,1,2,3,4,5,6,7,8};
int main() {
  ll N;
  ll M;
    cin >>N>>M;
  vl a(M);
  vl b(M);
  rep(i,M) {
    ll aaa;
    ll bbb;
    cin >>aaa>>bbb;
    a.at(i)=aaa-1;
    b.at(i)=bbb-1;
  }

  ll count=0;
  do{
    bool psps=false;
    ll c=0;
    rep(i,N-1) {//startfirstrep
      bool pp=false;
      rep(j,M) {
        if((P[i]==a.at(j)) &&(P[i+1]==b.at(j))) {
          pp=true;
          break;
        }
      }
      
          rep(j,M) {
        if((P[i]==b.at(j)) &&(P[i+1]==a.at(j))) {
          pp=true;
          break;
        }
      }
    
    if(pp) {
      c++;
    }
    
      
    
    
      
      
      
      
      
      
      
    }//endfirstrep 
    
    if((c==N-1)&&(P[0]==0)) {
      count++;
    }
    
    
    
  }
  while(next_permutation(P,P+N));
  
  
  cout<<count<<endl;
}



  
      
  