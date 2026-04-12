#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

typedef   signed long long int slli;
typedef unsigned long long int ulli;
const slli MAX_SLLI = 0x7FFFFFFFFFFFFFFF;
const slli MIN_SLLI = 0x8000000000000000;
const ulli MAX_ULLI = 0xFFFFFFFFFFFFFFFF;
const ulli MIN_ULLI = 0x0000000000000000;

#define N_TIMES(i, n)     for (ulli i = 0;     i <  n; ++i)
#define N_TIMES_REV(i, n) for (slli i = n - 1; i >= 0; --i)

#ifdef __DEBUG__
template<typename T>
std::ostream& operator<<(std::ostream &os, const std::list<T> &list)
{
  const std::string delim = ", ";
  typename std::list<T>::const_iterator itr = list.begin();
  while (itr != list.end()) {
    os << *itr;
    ++itr;
    if(itr != list.end()) os << delim;
  }
  return os;
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &v)
{
  const std::string delim = ", ";
  for (unsigned n = 0; n < v.size(); ++n) {
    os << v[n];
    if((n + 1) < v.size()) os << delim;
  }
  return os;
}
#endif /* __DEBUG__ */

int main(int argc, char **argv)
{
  long A, B, C, X, Y;
  std::cin >> A >> B >> C >> X >> Y;
  
  // ABを z (<= Z) 枚買う
  long Z = 2 * std::max(X, Y);
  long S = MAX_SLLI;
  for (long z = 0; z <= Z; ++z) {
    long x = std::max(static_cast<long>(0), X - (z / 2));
    long y = std::max(static_cast<long>(0), Y - (z / 2));
    
    long s = A * x + B * y + C * z;
    
    S = std::min(s, S);
  }
  std::cout << S << std::endl;
  
  return 0;
}