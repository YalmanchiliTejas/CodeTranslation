#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define ALL(v) v.begin(),v.end()
#define FOR(i, j, k) for(ll i=j;i<k;i++)
#define DUMP(i, v)for(ll i=0;i<v.size();i++)cout<<v[i]<<" "

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<ll, ll> P;
typedef long double ld;
struct Edge{ll from, to, cost;};
struct node{ll cost, to;
  bool friend operator>(node a, node b){
    return a.cost>b.cost;
  }
};

ll mod(ll a, ll mod){
  ll res = a%mod;
  if(res<0)res=res + mod;
  return res;
}

ll modpow(ll a, ll n, ll mod){
  ll res=1;
  while(n>0){
    if(n&1) res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll modinv(ll a, ll mod){
  return modpow(a, mod-2, mod);
}

ll gcd(ll a, ll b){
  ll r = a%b;
  if(r==0) return b;
  else return gcd(b, a%b);
}

bool is_prime(ll n){
  ll i = 2;
  if(n==1)return false;
  if(n==2)return true;
  bool res = true;
  while(i*i <n){
    if(n%i==0){
      res = false;
    }
    i = i+1;
  }

  //if(i==1)res = false;
  if(n%i==0)res=false;
  return res;
}
ll N;
ll M;
llvec e[20];
ll cnt;

ll dfs(ll cur, set<ll> visited){
  if(visited.count(cur)!=0){
    return 0;
  }else{
    visited.insert(cur);
    if(visited.size()==N){
      return 1;
    }
    ll ans = 0;
    rep(i, e[cur].size()){
      ans += dfs(e[cur][i], visited);
    }
    return ans;
  }
}

/**************************************
** A main function starts from here  **
***************************************/
int main(){
  cin >> N >> M;
  rep(i, M){
    ll a,b;
    cin >> a >> b;
    a--;b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  set<ll> v;
  cout << dfs(0, v);

  return 0;
}
