#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
#define rep(i,n) for(auto i=0;i<(n);i++)
#define rep1(i,n) for(auto i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

using namespace std;


struct init{ init(){ cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20); }; }aaaaaaa;


ll mod = 1e9 + 7;

ll powmod(ll b){
    ll r = 1;
    ll c = mod-2;
    for (; c>0; c>>=1, b=b*b%mod){
        if (c&1)    r = r*b%mod;
    }
    return r;
}

ll powdiv(ll a, ll b){
    return a * powmod(b) % mod;
}

ll solve(ll n, ll k){
  ll allSum = 0;
  rep(d, n) allSum += d*(n-d), allSum %= mod;

  return allSum;
}

int main(){
  ll n, m, k;
  cin >> n >> m >> k;

  ll pat = n*m;

  ll c = 1;
  rep(i, k-2){
    c *= (pat-i-2) % mod;
    c %= mod;
    c = powdiv(c, i+1);
  }

  ll allSum = 0;
  ll nSum = solve(n, k);
  allSum += pow(m, 2) * nSum;
  allSum %= mod;

  ll mSum = solve(m, k);
  allSum += pow(n, 2) * mSum;
  allSum %= mod;

  allSum *= c;
  allSum %= mod;

  cout << allSum << endl;
  


  return 0;
}
