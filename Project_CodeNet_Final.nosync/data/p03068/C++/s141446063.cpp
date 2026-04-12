#include <bits/stdc++.h>

using namespace std;

#define N_TIMES(i, n)     for (ulli i = 0;     i <  n; ++i)
#define N_TIMES_REV(i, n) for (slli i = n - 1; i >= 0; --i)

#ifdef __DEBUG__

template<typename T, typename U>
ostream& operator<<(ostream &os, const pair<T, U> &pair)
{
  os << pair.first << ": " << pair.second;
  return os;
}

template<class ForwardIterator>
ostream& _iterator_to_display(
  ostream &os, 
  ForwardIterator begin, ForwardIterator end, 
  const string &delim = ", "
)
{
  auto itr = begin;
  while (itr != end) {
    os << *itr;
    ++itr;
    if (itr != end) os << delim;
  }
  return os;
}

template<typename T>
ostream& operator<<(ostream &os, const list<T> &list)
{
  os << '[';
  _iterator_to_display(os, list.begin(), list.end());
  os << ']';
  return os;
}

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &vector)
{
  os << '[';
  _iterator_to_display(os, vector.begin(), vector.end());
  os << ']';
  return os;
}

template<typename T, class C=less<T>>
ostream& operator<<(ostream &os, const set<T> &set)
{
  os << '{';
  _iterator_to_display(os, set.begin(), set.end());
  os << '}';
  return os;
}

template<typename T, class C=less<T>>
ostream& operator<<(ostream &os, const multiset<T> &set)
{
  os << '{';
  _iterator_to_display(os, set.begin(), set.end());
  os << '}';
  return os;
}

template<typename T, typename U, class C=less<T>>
ostream& operator<<(ostream &os, const map<T, U> &map)
{
  os << '{';
  _iterator_to_display(os, map.begin(), map.end());
  os << '}';
  return os;
}

template<typename T, typename U, class C=less<T>>
ostream& operator<<(ostream &os, const multimap<T, U> &map)
{
  os << '{';
  _iterator_to_display(os, map.begin(), map.end());
  os << '}';
  return os;
}

#define debug(var) cerr << #var" = " << var << endl

#endif /* __DEBUG__ */

int main(int argc, char **argv)
{
  uint64_t N, K;
  string S;
  
  cin >> N >> S >> K;
  
  string T = S;
  char c = S[K - 1];
  
  for (uint64_t i = 0; i < S.size(); ++i) {
    T[i] = (S[i] != c) ? '*' : S[i];
  }
  
  cout << T << endl;
  
  return 0;
}