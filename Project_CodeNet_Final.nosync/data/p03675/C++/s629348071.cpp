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


int main(const int argc, char * argv [])
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  size_t n;
  cin >> n;
  vector<int> a(n);
  cin >> a;

  vector<int> out;
  out.reserve(n);
  for(size_t i = 0; i < n; i += 2)
    out.push_back(a[i]);

  reverse(begin(out), end(out));
  for(size_t i = 1; i < n; i += 2)
    out.push_back(a[i]);

  if(!(n & 1))
    reverse(begin(out), end(out));

  dump(begin(out), end(out), " ");

  return EXIT_SUCCESS;
}
