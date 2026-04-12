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

#define __DEBUG__ 1

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

typedef std::vector< std::vector<bool> > EdgeTable;

typedef std::bitset<8> VisitedFlags;
const VisitedFlags NullFlags(0);

inline bool complete(unsigned N, const VisitedFlags &visited)
{
  N_TIMES(n, N) { 
    if(!visited[n]) return false;
  }
  return true;
}

unsigned search(const EdgeTable &edge, unsigned node, const VisitedFlags &visited)
{
  unsigned N = edge.size();
  unsigned count = 0;

  if(complete(N, visited)) return 1;

  for (unsigned next = 0; next < N; ++next) {
    if (visited[next]) continue;
    if (!edge[node][next]) continue;
    
    VisitedFlags flags = visited;
    flags.set(next);
    count += search(edge, next, flags);
  }

  return count;
}

unsigned search(const EdgeTable &edge)
{
  unsigned start = 0;

  VisitedFlags visited = NullFlags;
  visited.set(start);

  return search(edge, start, visited);
}

int main()
{
  unsigned N, M;
  std::cin >> N >> M;

  EdgeTable edge(N);
  N_TIMES(n, N) {
    edge[n] = std::vector<bool>(N, false);
  }

  N_TIMES(m, M) {
    unsigned a, b;
    std::cin >> a >> b;
    
    edge[a - 1][b - 1] = edge[b - 1][a - 1] = true;
  }

  std::cout << search(edge) << std::endl;

  return 0;
}