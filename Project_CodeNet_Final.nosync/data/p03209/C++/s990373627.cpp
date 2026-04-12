#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<endl
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define mp make_pair
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define sz(x) (int)(x).size()
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pll = pair<ll, ll>;
ll h(vll f,vll p,ll n,ll x){
  if(x==1&&n==0){
    return 1;
  }
  else if(x==1){
    return 0;
  }
  else if(x<2+f[n-1]){
    return h(f,p,n-1,x-1);
  }
  else if(x==(2+f[n-1])){
    return 1+p[n-1];
  }
  else if(x<3+2*f[n-1]){
    return p[n-1]+1+h(f,p,n-1,x-2-f[n-1]);
  }
  else if(x==3+2*f[n-1]){
    return 2*p[n-1]+1;
  }
}
  
int main(){
  ll n,x;
  cin>>n>>x;
  vll f(51);
  vll p(51);
  f[0]=1;
  p[0]=1;
  for(int i=1;i<51;i++){
    f[i]=f[i-1]*2+3;
    p[i]=p[i-1]*2+1;
  }
  COUT(h(f,p,n,x));
}
