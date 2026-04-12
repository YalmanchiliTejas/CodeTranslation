#include<iostream>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define ll  long long 
const ll INF=1LL<<60;
const ll mod=1000000007;
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
vector<vector<bool>>d(10001,vector<bool>(10010));
vector<pair<ll,ll>>s[100001];
ll dis[100001];
int main(){
  ll a;cin>>a;
  vector<ll>b(a),c(a),sum(a+1,0);
  rep(i,a)cin>>b[i];
  for(ll i=a-1;i>=0;i--){
    sum[i]+=b[i]+sum[i+1];
    sum[i]%=mod;
  }
  ll kotae=0;
  rep(i,a-1){
    kotae+=b[i]*sum[i+1];
    kotae%=mod;
  }
  cout<<kotae;
}
