#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
const int INF = 1e9;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

int main()
{
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> a(M);
  std::vector<long long> b(M);
  vector<int> graph[10];
  for (int i = 0; i < M; i++)
  {
    scanf("%lld", &a[i]);
    scanf("%lld", &b[i]);
    a[i]--;
    b[i]--;
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }
  vector<int> v(N);
  iota(v.begin(), v.end(), 0);
  int cnt = 0;
  do
  {
    if (v[0] != 0)
      continue;
    bool flag = true;
    for (int i = 1; i < N; ++i)
    {
      bool t = false;
      for (int j = 0; j < graph[v[i - 1]].size(); ++j)
      {
        if (graph[v[i - 1]][j] == v[i])
        {
          t = true;
          break;
        }
      }
      if (!t)
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      cnt++;
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << cnt << endl;

  return 0;
}
