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

ll d[20][20];

int main(){
  ll n,m;
  cin>>n>>m;
  clr(d,0);
  rep(i,0,m){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    d[a][b]=1;
    d[b][a]=1;
  }
  vector<ll> v;
  rep(i,1,n){
    v.pb(i);
  }
  ll c = 0;
  do{
    vector<ll> v1;
    v1.pb(0);
    rep(i,0,v.sz){
      v1.pb(v[i]);
    }
    int flag = 1;
    rep(i,0,v1.sz-1){
      if(d[v1[i]][v1[i+1]]==0){
        flag = 0;
      }
    }
    if(flag==1)c++;
  }while(next_permutation(all(v)));
  cout << c << endl;
  return 0;
}



