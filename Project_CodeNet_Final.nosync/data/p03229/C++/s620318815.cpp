#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
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
using vc = vector<char>;
using vvc = vector<vc>;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n;
  cin>>n;
  vll a(n);
  PQR big;
  PQ small;
  rep(i,n){
    cin>>a[i];
    big.pu(a[i]);
    small.pu(a[i]);
  }
  ll ans=0;
  ll ss=big.top();
  big.pop();
  ll bb=small.top();
  small.pop();
  ans=abs(bb-ss);
  ll cu=2;
  while(cu<n){
    if(n-cu==1){
      ll now=big.top();
      ans+=max(abs(bb-now),abs(ss-now));
      break;
    }
    ll sss=big.top();
    big.pop();
    ans+=abs(bb-sss);
    ll bbb=small.top();
    small.pop();
    ans+=abs(ss-bbb);
    ss=sss;
    bb=bbb;
    cu+=2;
  }
  COUT(ans);
}