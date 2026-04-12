#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define ALL(x) x.begin(),x.end()
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

inline bool LT(double a,double b) { return !equals(a,b) && a < b; }
inline bool LTE(double a,double b) { return equals(a,b) || a < b; }

map<ll,int> prime_factor(ll n) {
  map<ll,int> res;
  for(ll i=2;i*i<=n;i++) {
    while(n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if(n != 1)res[n] = 1;
  return res;
}

int n;
vector<ll> vec;
void compute() {
  vector<ll> pf;
  rep(i,n) {
    map<ll,int> tmp = prime_factor(vec[i]);
    for(auto v : tmp) {
      if( v.first > 1LL ) {
	pf.push_back(v.first);
      }
    }
  }
  sort(ALL(pf));
  pf.erase(unique(ALL(pf)),pf.end());

  ll maxi = 0;
  rep(i,(int)pf.size()) {
    ll p = pf[i];
    ll sum = 0;
    rep(j,n) {
      if( vec[j] % p == 0 ) sum += vec[j];
    }
    maxi = max(maxi,sum);
  }
  cout << maxi << endl;
}

int main() {
  cin >> n;
  vec.resize(n);
  rep(i,n) cin >> vec[i];
  compute();
  return 0;
}

