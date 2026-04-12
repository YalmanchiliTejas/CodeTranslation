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

constexpr ll LNF = 1ll<<60;

constexpr int INF = 1e9+7;

vector<int> dx = {-1,0,1,0,-1,1,-1,1};
vector<int> dy = {0,-1,0,1,1,-1,-1,1};

/* template */

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    int flag = 0;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    ll s = 0;
    rep(i,0,n){
        s += a[i]/n;
        if(a[i]>=n) flag = 1;
    }
    ll ans = 0;
    while(flag){
        flag = 0;
        ans += s;
        ll cmp = s;
        s = 0;
        rep(i,0,n){
            a[i] += cmp -(n+1ll)*(a[i]/n);
            s += a[i]/n;
            if(a[i]>=n) flag= 1; 
        }
        debug(a);
        if(flag==0) break;
    }
    cout << ans << endl;
}