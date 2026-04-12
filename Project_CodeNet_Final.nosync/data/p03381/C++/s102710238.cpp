#include<bits/stdc++.h>
#include <iostream>
#include <string>
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
using vvll = vector<vll>;
using vstr = vector<string>;
using pll = pair<ll, ll>;
int main(){
  ll n;
  cin>>n;
  vll x(n);
  vll y(n);
  rep(i,n) {
    cin>>x[i];
    y[i]=x[i];
  }
  sort(all(y));
  ll k=y[n/2];
  rep(i,n){
    ll g=x[i];
    if(g<k){
      COUT(k);
    }
    else{
      COUT(y[n/2-1]);
    }
  }
}