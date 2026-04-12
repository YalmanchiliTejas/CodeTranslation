#include <bits/stdc++.h>
//#pragma once
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<double,double> P;
const ll INF = 1e16;
const int MOD = 998244353;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 



///////////////////////___modpow___////////////////////
ll modpow(ll a,  ll n, const ll &MOD = MOD){
  ll ret = n == 0 ? 1 : modpow(a, n/2, MOD);
  (ret *= ret) %= MOD;
  if(n%2)((ret *= a) %= MOD);
  return ret;
}
///////////////////////___modinv___////////////////////
ll modinv(ll d, const ll &MOD = MOD){
  return modpow(d, MOD-2, MOD);
}
///////////////////////___combination___////////////////////
vector<ll> fac, finv, inv;
void COMinit(const int MAX = 5000000, const ll &MOD = MOD){
  fac.resize(MAX);finv.resize(MAX);inv.resize(MAX);
  fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
  repd(i,2,MAX){
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}
ll COM(int n, int k){
  if(n < k)return 0;
  if(n < 0 || k < 0)return 0;
  return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}


//////////////////////////////////////////////////////
class union_find{
  int N;vector<int> par;
  public:
    union_find(int n){
      N = n;
      par.resize(N);
      rep(i,N)par[i] = -1;
    }
    int find(int x){
      if(par[x] < 0)return x;
      else{
        return par[x] = find(par[x]);
      }
    }
    void unite(int x, int y){
      x = find(x);
      y = find(y);
      if(x == y)return;
      par[y] += par[x];
      par[x] = y;
    }
    bool same(int x, int y){
      return find(x) == find(y);
    }
    int size(int x){
      return -par[find(x)];
    }
};
//////////////////////////////////////////////////////
///////////////////////___inPrime___////////////////////
bool isPrime(int n){
  for(int i = 2;i*i <= n;i++){
    if(n % i == 0)return false;
  }
  return n != 1;
}

///////////////////////___divisor___////////////////////
vector<int> divisor(int n){
  vector<int> ret;
  for(int i = 1;i*i <= n;i++){
    if(n % i == 0){
      ret.push_back(i);
      if(n/i != i)ret.push_back(n/i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

///////////////////////___prime_factor___////////////////////
map<int, int> prime_factor(int n){
  map<int, int> ret;
  for(int i = 2;i*i <= n;i++){
    while(n % i == 0){
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1){
    ret[n] = 1;
  }
  return ret;
}

///////////////////////___sieve___////////////////////////////
vector<int> primes;vector<bool> is_prime;
int sieve(int n){
  int p = 0;primes.resize(n);
  is_prime.resize(n+1);rep(i,n+1)is_prime[i] = true;is_prime[0] = is_prime[1] = false;
  repd(i, 2, n+1){
    if(is_prime[i]){
      primes[p++] = i;
      for(int j = 2;j <= n;j += i)is_prime[j*i] = false;
    }
  }
  return p;
}

/////////////////////////////////////////////////////////////////

struct SegmentTree {
private:
  int N, uni = 0;vector<int>  node;
public:
  SegmentTree(){}
  int look(int x, int y){
    return max(x, y);
  }
  void init(vector<int> v){
    int sz = v.size();
    N = 1;while(N < sz)N *= 2;
    node.resize(2*N-1, uni);

    rep(i,sz)node[i+N-1] = v[i];//最下段に値を入れる
    for(int i=N-2;i >= 0;i--)node[i] = look(node[2*i+1], node[2*i+2]);//上げていく
  }
  void update(int x, int val){
    x += (N-1);//最下段へ
    node[x] = val;
    while(x > 0){//上げていく
      x = (x-1)/2;
      node[x] = look(node[2*x+1], node[2*x+2]);
    }
  }
  int get(int a, int b, int k=0, int l=0, int r=-1){
    if(r < 0)r = N;
    if(r <= a || b <= l)return uni;
    if(a <= l && r <= b)return node[k];
    int vl = get(a, b, 2*k+1, l, (l+r)/2);
    int vr = get(a, b, 2*k+2, (l+r)/2, r);
    return look(vl, vr);
  }
};
////////////////////////////////////////////////////////////////////

const string yy = "Yes", nn = "No";


signed main(){
  string s;cin>>s;
  bool b = false;
  rep(i,s.length()-1){
    if(s[i] == 'A' && s[i+1] == 'C'){
      b = true;
    }
  }
  if(b)cout << yy << endl;
  else cout << nn << endl;
}



