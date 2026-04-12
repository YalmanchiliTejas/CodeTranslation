#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip> 

using ll = long long;
using ull = unsigned long long;
using namespace std;

#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i = 0;(i) < ((int)(n));++(i))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define test(a) cout<<"line:"<<__LINE__<<"["<<(#a)<<": "<<(a)<<"]"<<endl

constexpr int INF = 1e9+7;
constexpr ll INFL = 9*1e18;

constexpr int dx[4] = { 1, 0, -1, 0 };
constexpr int dy[4] = { 0, 1, 0, -1 };

// constexpr int dx[8] = {1, 1, 0,-1,-1,-1, 0, 1};
// constexpr int dy[8] = {0, 1, 1, 1, 0,-1,-1,-1};

int inline digit(ll num){int tmp = 0;while(num){tmp++;num/=10;}return tmp;} // 桁数
template<typename T>inline T SUM(vector<T> vec){return accumulate(all(vec),(T)0);} // vectorの中身を全部足す
template<typename T>inline T digitSum(T num){T sum = 0;while(num){sum+=num%10;num/=10;}return sum;} // 各桁の和
template<typename T>inline T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);} // 最大公約数
template<typename T>inline T lcm(T a, T b){T g = gcd(a,b);return a/g*b;} // 最小公倍数
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T>inline void print(T&& x){cout<<setprecision(32)<<x<<endl;}


// TODO: write
int main() {
  #define int ll
  
  ll n,x,m;cin>>n>>x>>m;
  vector<ll> a;
  
  a.pb(x);
  map<ll,int> tmp;
  tmp[x]++;
  ll begin = -1;
  for(int i = 0;;i++){
    if(tmp[a[i]*a[i]%m]){
      begin = a[i]*a[i]%m;
      break;
    }
    a.pb(a[i]*a[i]%m);
    if(a[i+1] == 0){
      print(SUM(a));
      return 0;
    }
    tmp[a[i+1]]++;
  }
  
  vector<ll> b;
  ll ans = 0;
  bool exist = false;
  rep(i,min((ll)a.size(),n)){
    if(begin == a[i])exist = true;
    if(exist){
      b.pb(a[i]);
    }else{
      ans += a[i];
    }
  }
  if(!b.size() || a.size() >= n){
    print(ans + SUM(b));
    return 0;
  }
  
  n -= a.size() - b.size();
  ans += (n / b.size()) * SUM(b);
  rep(i,n%b.size()){
    ans += b[i];
  }
  print(ans);
  return 0;
}