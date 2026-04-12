#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

const int N = (int)3e5;

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size() > n) return kaijo_memo[n];
  if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
  while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
  return kaijo_memo[n];
}
ll nCr(ll n, ll r){
  if(n < r || r < 0) return 0;
  ll ret = 1;
  ret *= kaijo(n); ret %= MOD;
  ret *= mpow(kaijo(r), MOD-2); ret %= MOD;
  ret *= mpow(kaijo(n-r), MOD-2); ret %= MOD;
  return ret;
}

ll powa(ll a, ll b){
  ll ret = 1;
  rep(i,b){
    ret *= a;
  }
  return ret;
}

int main(void){
  ll k;cin>>k;
  ll base=0,seki=0,memo=0;
  while(true){
    seki = 0;
    rep(i,8){
      seki += powa(base,i);
    }
    if(seki > k || memo > seki){
      base--;
      break;
    }
    base++;
    memo = seki;
  }
  seki = 0;
  rep(i,8){
    seki += powa(base,i);
    cerr<<"i:"<<i<<"seki:"<<seki<<"powa:"<<powa(base,i)<<endl;
  }
  ll remain = k - seki;
  cerr<<"remain:"<<remain<<endl;
  vector<ll> ans;
  rep(i,8){
    ans.push_back(0);
  }
  if(base <= 1){
    ans[0] += remain;
  }else{
    rep(i,7){
      ans[i] += remain % base;
      remain /= base;
    }
    ans[7] += remain;
  }
  cerr<<"base:"<<base<<endl;
  cerr<<ans[0]<<endl;
  /*cerr<<base<<endl;
  rep(i,8){
    cerr<<ans[i]<<" ";
  }
  cerr<<endl;*/
  ll debug = 0;
  rep(i,8){
    debug += powa(base, i) * (ans[i] + 1);
  }
  cerr<<k<<" "<<debug<<endl;
  while(debug != k){

  }
  string fest = "FESTIVAL";
  rep(i,7){
    rep(j,base){
      cout<<fest[i];
    }
  }
  REP(i,8){
    rep(j,ans[i]){
      cout<<fest[i];
    }
  }
  rep(i,8){
    cout<<fest[i];
  }
  cout<<endl;
  return 0;
}
