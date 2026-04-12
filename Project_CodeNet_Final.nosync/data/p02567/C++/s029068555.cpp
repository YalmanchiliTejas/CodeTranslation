#include <iostream>
#include<atcoder/segtree>
//#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <queue>
//#include <deque>
//#include <bitset>
#include <math.h>
using namespace std ;
using namespace atcoder ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}
void chmax(ll &a,ll b){	if(a<b) a = b ;}
void chmin(ll &a,ll b){ if(a>b) a = b ;}

ll op(ll a,ll b){return max(a,b) ;}
ll e(){return -INF ;}
ll border ;
bool f(ll v){return v<border ;}

int main(){
  ll n,q ;
  cin >> n >> q ;
  vll a(n) ;
  for(auto &i:a) cin >> i ;
  segtree<ll,op,e> sgt(a) ;
  while(q--){
    ll t,u,v ;
    cin >> t >> u >> v ;
    if(t==1){
      sgt.set(u-1,v) ; 
    }
    if(t==3){
      border = v ;
      cout << sgt.max_right<f>(u-1)+1 << endl ;
    }
    if(t==2){
      cout << sgt.prod(u-1,v) << endl ;
    }
  }
}
