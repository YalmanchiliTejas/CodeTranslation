#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2> &pair) const {
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

int main()
{
  int N;
  std::cin >> N;
  int m[N];
  int res = 0;
  int max = 0;
  for (int i=0; i<N; i++) {
    std::cin >> m[i];
    if (max <= m[i]) {
      res++;
      max = m[i];
    }
  }

  std::cout << res;

  return 0;
}
