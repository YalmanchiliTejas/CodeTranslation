#include <bits/stdc++.h>
#ifdef BUG
    #include "debug.hpp"
#else
    #define DEBUG(var)
#endif

using namespace std;
template< class T1, class T2 > inline istream &
operator>>( istream & fin, pair< T1, T2 > & pr )
{ fin >> pr.first >> pr.second; return fin; }
template< class T0, class T1, class T2 > inline istream &
operator>>( istream & fin, tuple< T0, T1, T2 > & t )
{ fin >> get<0>(t) >> get<1>(t) >> get<2>(t); return fin; }
template< class T > inline istream &
operator>>( istream & fin, vector< T > & a ) {
for(auto & u: a) fin >> u; return fin; }
template<class T, size_t n> inline istream &
operator>>( istream & fin, array<T, n> & a ) {
for(auto & u: a) fin >> u; return fin; }
template<class FwdIter> inline auto
dump(FwdIter first, FwdIter last, const char * dlm = " ") -> void {
typedef typename iterator_traits<FwdIter>::value_type value_type;
copy(first, last, ostream_iterator<value_type>(cout, dlm)); }
template<typename T> vector<T> & operator--(vector<T> & a)
{ for(auto & i: a) --i; return a; }
/* @@@ ----------------------------------- */


inline size_t
find(const size_t i, vector<int> & par)
{
    return par[i] < 0 ? i : par[i] = find(par[i], par);
}

inline void
join(size_t i, size_t j, vector<int> & par)
{
    if((i = find(i, par)) != (j = find(j, par)))
    {
        if(par[j] < par[i]) swap(i, j);
        par[i] += par[j];
        par[j] = i;
    }
}


int64_t
arc076_b()
{
  size_t n;
  cin >> n;

  vector<pair<int64_t, int64_t>> xs(n);
  cin >> xs;

  typedef pair<size_t, size_t> edge_t;
  vector<edge_t> edge;
  {
    vector<size_t> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&xs](const size_t i, const size_t j) {
         return xs[i] < xs[j];
         });
    for(size_t i = 0; i + 1 < n; ++i)
      edge.emplace_back(idx[i], idx[i + 1]);
  }
  {
    vector<size_t> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&xs](const size_t i, const size_t j) {
         return xs[i].second < xs[j].second;
         });
    for(size_t i = 0; i + 1 < n; ++i)
      edge.emplace_back(idx[i], idx[i + 1]);
  }

  sort(begin(edge), end(edge), [&xs](const edge_t & a, const edge_t & b){
       const auto d = min(abs(xs[a.first].first  - xs[a.second].first),
                          abs(xs[a.first].second - xs[a.second].second));

       const auto e = min(abs(xs[b.first].first  - xs[b.second].first),
                          abs(xs[b.first].second - xs[b.second].second));

       return d < e;
       });


  vector<int> par(n, -1); /* each node its own parent */

  size_t k = 0;
  int64_t out = 0;

  for(const auto & e: edge)
    if(find(e.first, par) != find(e.second, par))
    {
      join(e.first, e.second, par);
      ++ k;

      out += min(abs(xs[e.first].first  - xs[e.second].first),
                 abs(xs[e.first].second - xs[e.second].second));

      if(k + 1 == n)
        break;
    }

  return out;
}

int main(const int argc, char * argv [])
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout << arc076_b();

  return EXIT_SUCCESS;
}
