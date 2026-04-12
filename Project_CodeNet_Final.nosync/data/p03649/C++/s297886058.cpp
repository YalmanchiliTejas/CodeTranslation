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

// http://arc079.contest.atcoder.jp/tasks/arc079_c

int64_t run()
{
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  cin >> a;

  // const int64_t acc = accumulate(begin(a), end(a), (int64_t)0);
  bool loop = true;
  int64_t k = 0;
  while(loop)
  {
    loop = false;
    vector<int64_t> cnt(n, 0);

    for(int64_t i = 0; i < n; ++i)
      if(n < a[i] + 1)
      {
        cnt[i] = a[i] / n;
        k += cnt[i];
        a[i] %= n;
        loop = true;
      }

    const int64_t acc = accumulate(begin(cnt), end(cnt), (int64_t) 0);
    for(int64_t i = 0; i < n; ++i) a[i] += acc - cnt[i];
  }

  return k;
}

int main(const int argc, char * argv [])
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout << run();

  return EXIT_SUCCESS;
}
