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
/*
//#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
*/

// C++
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
/*
//#if __cplusplus >= 201103L
#include <array>
#include <chrono>
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
*/
using namespace std;
#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl

#define uni(x) x.erase(unique(all(x)),x.end())
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000
#define M_INF 1000000000
int n,m,v,i;
void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w;
  cin>>h>>w;
  string p[101];
  bool t[101][101];
  rep(i,h)rep(j,w) t[i][j] = true;
  rep(i,h) cin>>p[i];
  rep(i,h){
    rep(j,w){
      // cout<<t[i][j];
    }
    // cout<<endl;
  }
  rep(i,h){
    ll cnt = 0;
    rep(j,w) {if(p[i][j] == '#') cnt++;}
    if(cnt==0) {rep(j,w) t[i][j] = false;}
  }rep(i,h){
    rep(j,w){
      // cout<<t[i][j];
    }
    // cout<<endl;
  }
  rep(i,w){
    ll cnt = 0;
    rep(j,h) {if(p[j][i] == '#') cnt++;}
    if(cnt==0) {rep(j,h) t[j][i] = false;}
  }
  rep(i,h){
    rep(j,w){
      // cout<<t[i][j];
    }
    // cout<<endl;
  }
  rep(i,h){
    ll cnt = 0;
    rep(j,w){
      if(t[i][j]!= false) {
        cout<<p[i][j];
        cnt++;
      }
    }
    if(cnt!=0) cout<<endl;
  }

}

int main(){
  solve();
  return 0;
}
