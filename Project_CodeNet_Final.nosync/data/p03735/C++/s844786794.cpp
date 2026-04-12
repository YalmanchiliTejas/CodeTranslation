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

// http://arc073.contest.atcoder.jp/tasks/arc073_c

int main(const int argc, char * argv [])
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  size_t n;
  cin >> n;
  vector<pair<int64_t, int64_t>> xs(n);
  cin >> xs;

  typedef pair<int64_t, int64_t> value_t;
  const int64_t inf = numeric_limits<int64_t>::max();
  int64_t out = inf;

  // smallest value is red, largest one is blue
  // then it is optimal to always color the smaller value red
  for(auto & pr: xs)
    if(pr.second < pr.first) swap(pr.first, pr.second);

  {
    value_t a(inf, -inf), b(inf, -inf);
    for(const auto & pr: xs)
    {
      a.first = min(a.first, pr.first);
      a.second = max(a.second, pr.first);
      b.first = min(b.first, pr.second);
      b.second = max(b.second, pr.second);
    }

    out = (a.second - a.first) * (b.second - b.first);
  }

  // both the smaller and largest values are red
  // then we need smallest range of n disjoint endpoints

  const size_t size = 2 * n;

  vector<size_t> ord(size);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [n, &xs](const size_t i, const size_t j) {
       const auto x = i < n ? xs[i].first : xs[i - n].second;
       const auto y = j < n ? xs[j].first : xs[j - n].second;
       return x < y;
       });

  // idx of the other end in ord vector
  vector<size_t> idx(size);
  {
    vector<size_t> acc(n, 0);
    for(size_t i = 0; i < size; ++i)
      acc[ord[i] % n] += i;

    for(size_t i = 0; i < size; ++i)
      idx[i] = acc[ord[i] % n] - i;
  }

  DEBUG(out);
  DEBUG(ord);
  DEBUG(idx);

  if(idx[0] != size - 1)
  {
    int64_t val = inf;
    vector<bool> tag(size, false); // unavailable end-points

    for(size_t i = 1, j = 0, k = 0; ; ++i)  // [i, j]
    {
      for(; k < n && j + 1 < size;)
        if(!tag[++j])
        {
          ++ k;
          tag[idx[j]] = true; // make the other end unavailable
        }

      if(k != n)
        break;

      for(; tag[i]; ++i)
        ;

      const auto x = ord[i] < n ? xs[ord[i]].first : xs[ord[i] - n].second;
      const auto y = ord[j] < n ? xs[ord[j]].first : xs[ord[j] - n].second;
      val = min(val, y - x);

      // release other end of i
      tag[idx[i]] = false;
      if(idx[i] < i || j < idx[i])
        -- k;
    }

    const auto x = ord.front() < n ? xs[ord.front()].first : xs[ord.front() - n].second;
    const auto y = ord.back() < n ? xs[ord.back()].first : xs[ord.back() - n].second;
    val *= y - x;
    out = min(out, val);
  }

  cout << out;
  return EXIT_SUCCESS;
}

