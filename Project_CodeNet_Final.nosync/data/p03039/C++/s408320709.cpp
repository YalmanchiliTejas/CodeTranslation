#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize("Ofast")
using namespace std;
typedef int64_t ll;
typedef long double ld;
const ll INF=(1LL<<50);
const double inf=pow(10,10);
const ld pi=acosl(1);
const ll mod = 1000000007;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

template< typename T >
T binomial(int64_t N, int64_t K) {
  if(K < 0 || N < K) return 0;
  T ret = 1;
  for(ll i = 1; i <= K; ++i) {
    ret *= N--;
    ret /= i;
  }
  return ret;
}

using modint = ModInt< mod >;


void solve(){
	ll n,m,k;cin>>n>>m>>k;
	vector<ll>x;
	rep(i,n)rep(j,m)x.emplace_back(j+1);
	sort(all(x));
	//for(auto&&i:x)cout<<i<<endl;
	vector<modint>x_sum(n*m+1);
	x_sum[0]=0;
	rep(i,x.size()){
		x_sum[i+1]=x_sum[i]+x[i];
	}
	modint num=0;
	rep(i,x.size()){
		num+=x[i]*i;
		num-=x_sum[i];
	}
	modint a=binomial<modint>(n*m,k);
	modint b=binomial<modint>(k,2);
	modint c=binomial<modint>(n*m,2);
	//cout<<a<<" "<<b<<" "<<c<<endl;
	//cout<<a*b/c<<endl;
//	cout<<c<<endl;
	modint ans=0;
	ans+=num;
	//cout<<num<<" "<<ans<<endl;
	x.clear();
	//cout<<"startx"<<endl;
	for(auto&&i:x)cout<<i<<endl;
	rep(i,m)rep(j,n)x.emplace_back(j+1);
	sort(all(x));
	//for(auto&&i:x)cout<<i<<endl;
	x_sum[0]=0;
	rep(i,x.size()){
		x_sum[i+1]=x_sum[i]+x[i];
	}
	num=0;
	rep(i,x.size()){
		num+=x[i]*i;
		num-=x_sum[i];
		
	}
	ans+=num;
	//ans*=c;
	//cout<<c<<endl;
	cout<<ans*a*b/c<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<fixed;
	cout<<setprecision(30);
	solve();
}