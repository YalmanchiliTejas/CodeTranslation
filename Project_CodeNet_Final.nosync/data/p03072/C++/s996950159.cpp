#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template <class InputIterator, class Predicate>
typename iterator_traits<InputIterator>::difference_type
  mycount_if(InputIterator first, InputIterator last, Predicate pred) {
  typename iterator_traits<InputIterator>::difference_type ret = 0;
  for ( ; first != last; ++first)
    if (pred(first)) ret++;
  return ret;
}

int main()
{
  int N;
  cin >> N;
  vector<int> H(N);
  for_each(H.begin(), H.end(), [](int& e) { cin >> e; });
  int ans = 0;
  auto genLeqFunc = [](int X) {
    return [=](int& x) { return x <= X; };
  };
  cout << mycount_if(H.begin(), H.end(), [&](auto now) {
    auto leqHi = genLeqFunc(*now);
    return all_of(H.begin(), now, leqHi);
  }) << endl;
  return 0;
}
