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

typedef std::array<unsigned, 26> CharArray;

CharArray string2array(const std::string &S)
{
  CharArray array;
  std::fill(array.begin(), array.end(), 0);
  
  for (unsigned i = 0; i < S.size(); ++i) {
    ++array[S[i] - 'a'];
  }
  
  return array;
}

CharArray merge(const CharArray &A, const CharArray &B)
{
  CharArray array;
  std::fill(array.begin(), array.end(), 0);
  
  for (unsigned i = 0; i < 26; ++i) {
    array[i] = std::min(A[i], B[i]);
  }
  
  return array;
}

std::string array2string(const CharArray &A)
{
  std::string S;
  
  for (unsigned i = 0; i < 26; ++i) {
    for (unsigned j = 0; j < A[i]; ++j) {
      S.push_back('a' + i);
    }
  }
  
  return S;
}

int main()
{
  unsigned N;
  std::cin >> N;
  
  CharArray array;
  for (unsigned n = 0; n < N; ++n) {
    std::string S;
    std::cin >> S;
    
    CharArray a = string2array(S);
    
    if (n == 0) array = a;
    else {
      array = merge(array, a);
    }
  }
  
  std::cout << array2string(array) << std::endl;
  
  return 0;
}