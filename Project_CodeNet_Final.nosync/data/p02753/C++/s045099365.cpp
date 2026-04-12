#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using ulint = unsigned long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mjjj(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

template< typename T >
struct edge {
int src, to;
T cost;
//edge(int to) : src(-1),to(to),cost(-1){}
edge(int to, T cost) : src(-1), to(to), cost(cost) {}
edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
edge &operator=(const int &x) {
to = x;
return *this;
}
operator int() const { return to; }
};
template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< lint > >;
template< typename T >
using Matrix = vector< vector< T > >;
#define INF 1e+9
#define MAX_V 100000

// <最短距離, 頂点の番号>
using P = pair<lint, lint>;

lint V;
vector<edge<lint>> G[MAX_V];
lint d[MAX_V];

// void dijkstra(lint s) {
//     priority_queue<P, vector<P>, greater<P> > que;
//     fill(d, d+V, INF);
//     d[s] = 0;
//     que.push(P(0, s));

//     while (!que.empty()) {
//         P p = que.top();
//         que.pop();
//         lint v = p.second;
//         if (d[v] < p.first) continue;

//         for (lint i=0; i<G[v].size(); ++i) {
//             edge<lint> e = G[v][i];
//             if (d[e.to] > d[v] + e.cost) {
//                 d[e.to] = d[v] + e.cost;
//                 que.push(P(d[e.to], e.to));
//             }
//         }
//     }
// }
const lint mod = 1000000007;
struct mint {
  lint x; // typedef long long lint;
  mint(lint x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(lint t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

map< lint, lint > prime_factor(lint n) {
  map< lint, lint > ret;
  for(lint i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
lint MAX = 1000000000;
vector<lint> co;

bool dfs(lint from,lint to,lint par = -1){
    if(from == to){
        return true;
    }
    for(edge<lint> v : G[from]){
        if(v.to == par)continue;
        if(dfs(v.to,to,from)){
            co.push_back(v.cost);
            return true;
        }
    }
    return false;
}
lint digit(lint a,lint b){
    lint ad = 1,bd = 1;
    while(a > 9){
        ad++;
        a /= 10;
    }
    while(b > 9){
        bd++;
        b /= 10;
    }
    return max(ad,bd);
}

int main(){
    set<char> s;
    REP(i,3){
      char c;
      cin >> c;
      s.insert(c);
    }
    if(s.count('A') == 0 || s.count('B') == 0){
      cout << "No";
    }
    else{
      cout << "Yes";
    }

}

lint gcd(lint a, lint b)
{
if (a < b) {
a ^= b;
b ^= a;
a ^= b;
}
return b ? gcd(b, a % b) : a;
}
lint lcm(lint a, lint b)
{
return a * b / gcd(a, b);
}