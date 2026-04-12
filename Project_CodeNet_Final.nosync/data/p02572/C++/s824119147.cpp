#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <numeric>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <functional>
#include <limits>
#include <cassert>
#include <bitset>
 
using namespace std;
 
/* template */
 
using ll = long long;
 
void debug_out() { std::cout << std::endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << H << " ";
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cout << "debug: "; debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif
 
#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); i++)
#define rrep(i, a, n) for (int i = ((int)(n-1)); i >= (int)(a); i--)
#define Rep(i, a, n) for (long long i = (long long)(a); i< (long long)(n); i++)
#define RRep(i, a, n) for (long long i = ((long long)(n-1ll)); i>=(long long)(a); i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
struct Edge{
    int to;
    ll weight;
    Edge(int t, ll w) : to(t), weight(w){ }
};
 
struct edge{
    int from;
    int to;
    ll weight;
    edge(int f,int t,ll w) : from(f), to(t), weight(w){ }
};
 
 
using Graph = vector<vector<Edge>>;
using graph = vector<vector<int>>;
using edges = vector<edge>;
 
template <class T>
inline bool chmin(T &a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}
 
template <class T>
inline bool chmax(T &a, T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}
 
template <class T>
T lcm(T a, T b){
    return (a*b)/gcd(a,b);
}
 
ll ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
 
constexpr ll LNF = 1LL<<50;
 
constexpr int INF = 1e9+7;
 
const long double PI=3.14159265358979323846;
 
 
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};
 
/* template */

constexpr ll mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    mint ans = 0;
    mint b = a[0];
    rep(i,1,n){
        ans += b*a[i];
        b += a[i];
    }
    cout << ans << endl;
}
