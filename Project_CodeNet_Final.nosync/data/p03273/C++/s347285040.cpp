#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

const ll MOD = 1000000007;
const ll MAX = 200001;

ll mod(ll a){
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}

ll fac[MAX], finv[MAX], inv[MAX];

void nCrprep() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll nCr(ll n, ll r){
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}

ll nCrcheep(ll n,ll r){
  if(r == 0) return 1;
  else if(r == 1) return n;
  else return nCrcheep(n-1,r-1)*n/r;
}

int main(){
  ll h,w; cin >> h >> w;
  vector<vector<char>> table(h,vector<char>(w));
  
  rep(i,h){
    rep(j,w){
      cin >> table[i][j];
    }
  }
  
  ll hnotwhite = h;
  for(ll i=0; i < hnotwhite; i++){
    bool flag = true;
    rep(j,w){
      if(table[i][j] == '#') flag = false;
    }
    
    if(flag){
      hnotwhite--;
      for(ll j=i; j < h-1; j++){
        rep(k,w){
          table[j][k] = table[j+1][k];
        }
      }
      rep(j,w){
        table[h-1][j] = '.';
      }
      i--;
    }
  }
  
  
  ll wnotwhite = w;
  for(ll i=0; i < wnotwhite; i++){
    bool flag = true;
    rep(j,h){
      if(table[j][i] == '#') flag = false;
    }
    
    if(flag){
      wnotwhite--;
      for(ll j=i; j < w-1; j++){
        rep(k,h){
          table[k][j] = table[k][j+1];
        }
      }
      rep(j,h){
        table[j][w-1] = '.';
      }
      i--;
    }
  }
  
  rep(i,hnotwhite){
    rep(j,wnotwhite){
      cout << table[i][j];
      if(j == wnotwhite - 1) cout << endl;
    }
  }
  
  
}