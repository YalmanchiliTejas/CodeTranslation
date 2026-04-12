#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 4000000000000000000LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);
  std::cerr << std::fixed << std::setprecision(6);

  int N, A[222222], a[222222], m1, m2;

  std::cin >> N;

  for (int i = 0; i < N; i ++)
    std::cin >> A[i];

  memcpy(a, A, sizeof(A));

  std::sort(a, a + N);

  m1 = a[N / 2 - 1];
  m2 = a[N / 2];

  for (int i = 0; i < N; i ++)
    std::cout << (A[i] < m2 ? m2 : m1) << std::endl;
  
  return 0;
}
