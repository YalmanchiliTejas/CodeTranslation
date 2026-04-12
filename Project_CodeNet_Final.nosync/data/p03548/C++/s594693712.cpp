#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

const long long INF = 100000000;
const long long MOD = 1000000007;

std::vector<bool> IsPrime;

void sieve(size_t max)
{
  if (max + 1 > IsPrime.size())
  {                                // resizeで要素数が減らないように
    IsPrime.resize(max + 1, true); // IsPrimeに必要な要素数を確保
  }
  IsPrime[0] = false; // 0は素数ではない
  IsPrime[1] = false; // 1は素数ではない

  for (size_t i = 2; i * i <= max; ++i)     // 0からsqrt(max)まで調べる
    if (IsPrime[i])                         // iが素数ならば
      for (size_t j = 2; i * j <= max; ++j) // (max以下の)iの倍数は
        IsPrime[i * j] = false;             // 素数ではない
}

class Node{
public:
  long long w;
  long long v;
};

class UnionFind{
public:
  vector<long long> parent;
  UnionFind(long long N){
    parent.resize(N + 1);
    for (int i = 0; i < N;i++){

    }
  }
};

int main()
{
  long long X, Y, Z;
  cin >> X >> Y >> Z;
  X-=(2*Z);
  long long ans=0;
  while (X >= Y)
  {
    ans++;
    X -= Y;
    X -= Z;
  }
  cout << ans << endl;
}
