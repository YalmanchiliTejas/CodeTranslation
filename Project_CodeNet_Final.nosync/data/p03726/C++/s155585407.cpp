#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=(b-1);i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

vector<vector<ll> > vv;
int flag;

ll f(ll a, ll p){
  if(p!=-1&&vv[a].sz==1)return 1;
  ll c = 0;
  rep(i,0,vv[a].sz){
    if(vv[a][i]==p)continue;
    c += f(vv[a][i],a);
  }
  if(c==0){
    return 1;
  }
  else if(c==1){
    return 0;
  }
  else{
    flag = 1;
    return 0;
  }
}

int main() {
  flag = 0;
  ll n;
  cin>>n;
  vector<vector<ll> > vv_(n,vector<ll>());
  vv = vv_;
  rep(i,0,n-1){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    vv[a].pb(b);
    vv[b].pb(a);
  }
  ll res = f(0,-1);
  if(flag == 1){
    cout << "First" << endl;
    return 0;
  }
  if(res == 0){
    cout << "Second" << endl;
  }
  else{
    cout << "First" << endl;
  }
  return 0;
}