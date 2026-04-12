#ifndef KOMAKI_LOCAL
#define NDEBUG
#endif

#include <bits/stdc++.h>
#include <sys/time.h>
#include <unistd.h>
using namespace std;
#define i64         int64_t
#define rep(i, n)   for(i64 i = 0; i < ((i64)(n)); ++i)
#define sz(v)       ((i64)((v).size()))
#define bit(n)      (((i64)1)<<((i64)(n)))
#define all(v)      (v).begin(), (v).end()

std::string dbgDelim(int &i){ return (i++ == 0 ? "" : ", "); }
#define dbgEmbrace(exp) { int i = 0; os << "{"; { exp; } os << "}"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::vector<T> v);
template <class T> std::ostream& operator<<(std::ostream &os, std::set<T> v);
template <class T> std::ostream& operator<<(std::ostream &os, std::queue<T> q);
template <class T> std::ostream& operator<<(std::ostream &os, std::priority_queue<T> q);
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::pair<T, K> p);
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::map<T, K> mp);
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::unordered_map<T, K> mp);
template <int INDEX, class TUPLE> void dbgDeploy(std::ostream &os, TUPLE tuple){}
template <int INDEX, class TUPLE, class H, class ...Ts> void dbgDeploy(std::ostream &os, TUPLE t)
{ os << (INDEX == 0 ? "" : ", ") << get<INDEX>(t); dbgDeploy<INDEX + 1, TUPLE, Ts...>(os, t); }
template <class T, class K> void dbgDeploy(std::ostream &os, std::pair<T, K> p, std::string delim)
{ os << "(" << p.first << delim << p.second << ")"; }
template <class ...Ts> std::ostream& operator<<(std::ostream &os, std::tuple<Ts...> t)
{ os << "("; dbgDeploy<0, std::tuple<Ts...>, Ts...>(os, t); os << ")"; return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::pair<T, K> p)
{ dbgDeploy(os, p, ", "); return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::vector<T> v)
{ dbgEmbrace( for(T t: v){ os << dbgDelim(i) << t; }); }
template <class T> std::ostream& operator<<(std::ostream &os, std::set<T> s)
{ dbgEmbrace( for(T t: s){ os << dbgDelim(i) << t; }); }
template <class T> std::ostream& operator<<(std::ostream &os, std::queue<T> q)
{ dbgEmbrace( for(; q.size(); q.pop()){ os << dbgDelim(i) << q.front(); }); }
template <class T> std::ostream& operator<<(std::ostream &os, std::priority_queue<T> q)
{ dbgEmbrace( for(; q.size(); q.pop()){ os << dbgDelim(i) << q.top();   }); }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::map<T, K> mp)
{ dbgEmbrace( for(auto p: mp){ os << dbgDelim(i); dbgDeploy(os, p, "->"); }); }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::unordered_map<T, K> mp)
{ dbgEmbrace( for(auto p: mp){ os << dbgDelim(i); dbgDeploy(os, p, "->"); }); }
#define DBG_OUT std::cerr
#define DBG_OVERLOAD(_1, _2, _3, _4, _5, _6, macro_name, ...) macro_name
#define DBG_LINE() { char s[99]; sprintf(s, "line:%3d | ", __LINE__); DBG_OUT << s; }
#define DBG_OUTPUT(v) { DBG_OUT << (#v) << "=" << (v); }
#define DBG1(v, ...) { DBG_OUTPUT(v); }
#define DBG2(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG1(__VA_ARGS__); }
#define DBG3(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG2(__VA_ARGS__); }
#define DBG4(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG3(__VA_ARGS__); }
#define DBG5(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG4(__VA_ARGS__); }
#define DBG6(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG5(__VA_ARGS__); }

#define DEBUG0() { DBG_LINE(); DBG_OUT << std::endl; }
#define DEBUG(...)                                                      \
  {                                                                     \
    DBG_LINE();                                                         \
    DBG_OVERLOAD(__VA_ARGS__, DBG6, DBG5, DBG4, DBG3, DBG2, DBG1)(__VA_ARGS__); \
    DBG_OUT << std::endl;                                               \
  }



class UnionFind
{
public:
  int getGroupId(int index);
  void putTogether(int index0, int index1);

  UnionFind();
  UnionFind(int size);

private:
  int size;
  std::vector<int> parents;
};

inline UnionFind::UnionFind()
{
}

inline UnionFind::UnionFind(int size)
{
  this->size = size;
  parents = std::vector<int>(size);
  for(int i = 0; i < size; ++i){
    parents[i] = i;
  }
}

inline void UnionFind::putTogether(int index0, int index1)
{
  parents[getGroupId(index0)] = getGroupId(index1);
}

inline int UnionFind::getGroupId(int index)
{
  if(parents[index] == index) return index;
  return parents[index] = getGroupId(parents[index]);
}



void recur(i64 root, i64 pos, i64 parent, vector<i64> &path, vector<unordered_map<i64, vector<i64>>> &queries, vector<i64> &ans, vector<vector<pair<i64, i64>>> &edges)
{
  if(queries[root].count(pos)){
    i64 maxi = 0;
    for(i64 t: path) maxi = max(maxi, t);
    for(i64 index: queries[root][pos]) ans[index] = maxi;
  }
  for(pair<i64, i64> edge: edges[pos]){
    if(edge.first == parent) continue;
    path.push_back(edge.second);
    recur(root, edge.first, pos, path, queries, ans, edges);
    path.pop_back();
  }
}

int main()
{
  i64 n, m, q;
  i64 total_edge_cost = 0;
  cin >> n >> m;
  vector<pair<i64, pair<i64, i64>>> raw_edges(m);
  rep(i, m) cin >> raw_edges[i].second.first >> raw_edges[i].second.second >> raw_edges[i].first;
  rep(i, m) --raw_edges[i].second.first;
  rep(i, m) --raw_edges[i].second.second;
  sort(all(raw_edges));
  UnionFind uf(n);
  vector<vector<pair<i64, i64>>> edges(n);
  //DEBUG0();
  for(auto edge: raw_edges){
    if(uf.getGroupId(edge.second.first) == uf.getGroupId(edge.second.second)) continue;
    uf.putTogether(edge.second.first, edge.second.second);
    total_edge_cost += edge.first;
    edges[edge.second.first].push_back(make_pair(edge.second.second, edge.first));
    edges[edge.second.second].push_back(make_pair(edge.second.first, edge.first));
  }
  //DEBUG0();
  cin >> q;
  vector<unordered_map<i64, vector<i64>>> queries(n);
  rep(i, q){
    i64 a, b;
    cin >> a >> b;
    queries[a - 1][b - 1].push_back(i);
  }
  vector<i64> ans(q, -1);


  rep(root, n){
    vector<i64> path;
    recur(root, root, -1, path, queries, ans, edges);
  }

  rep(i, sz(ans)) cout << total_edge_cost - ans[i] << endl;
}



