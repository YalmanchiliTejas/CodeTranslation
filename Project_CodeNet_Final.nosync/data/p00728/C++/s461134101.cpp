#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char const* argv[])
{
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0) {
      break;
    }
    std::vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
      int s;
      std::cin >> s;
      scores[i] = s;
    }
    std::sort(scores.begin(), scores.end());
    scores.erase(scores.begin());
    scores.pop_back();
    int sum = std::accumulate(scores.begin(), scores.end(), 0);
    std::cout << (sum / (n - 2)) << std::endl;
  }
  return 0;
}