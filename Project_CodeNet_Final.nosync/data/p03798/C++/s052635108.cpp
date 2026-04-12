#include <iostream>
#include <sstream>
#include <algorithm>
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
#endif

const unsigned BITS_WIDTH = 1e+5 + 10;
typedef std::bitset<BITS_WIDTH> Animals;

#ifdef __DEBUG__
std::ostream& operator<<(std::ostream &os, const Animals &a)
{
  os << a.to_string();
  return os;
}
#endif

bool search(unsigned N, const std::string &s, Animals &result)
{
  std::vector<Animals> dp[2];
  dp[0] = std::vector<Animals>();
  dp[1] = std::vector<Animals>();
  
  N_TIMES(i, 4) {
    dp[0].emplace_back(i);
  }
  
  for (unsigned n = 1; n <= N; ++n) {
    for (const Animals &a : dp[(n - 1) % 2]) {
      Animals b(a);
      if (s[n - 1] == 'o') {
        b[n + 1] = a[n] ?  a[n - 1] : !a[n - 1];
      } else {
        b[n + 1] = a[n] ? !a[n - 1] :  a[n - 1];
      }
      dp[n % 2].push_back(b);
    }
    
    if ((n + 1) <= N) dp[(n - 1) % 2].clear();
  }
  
  for (const Animals &a : dp[N % 2]) {
    if ((a[0] == a[N + 0]) && (a[1] == a[N + 1])) {
      result = Animals(a);
      return true;
    }
  }
  
  return false;
}

int main()
{
  unsigned N;
  std::cin >> N;
  
  std::string s;
  std::cin >> s;
  
  Animals a;
  if (!search(N, s, a)) {
    std::cout << -1 << std::endl;
  } else {
    for (unsigned n = 1; n <= N; ++n) {
      std::cout << (a[n] ? 'S' : 'W');
    }
    std::cout << std::endl;
  }
  
  return 0;
}