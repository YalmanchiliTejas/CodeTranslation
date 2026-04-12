#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <stack>

typedef long long ll;
typedef std::vector< int > VI;

const double EPS = 1e-10;
const double PI  = acos(-1);
const ll     INF = 1 << 30;

ll gdb_exec(ll a, ll b) {
  if (b == 0) return a;
  return gdb_exec(b, a % b);
}

ll gdb(ll a, ll b) {
  if (a < b) std::swap(a, b);
  if (a == 0 || b == 0) return -999999999;
  return gdb_exec(a, b);
}

ll lcm(ll a, ll b) {
  ll gdb_val = gdb(a, b);
  if (a % gdb_val == 0) {
    return (a / gdb_val) * b;
  }
  return (b / gdb_val) * a;
}

int main(int argc, char* argv[])
{
  int r, g, b;
  std::cin >> r >> g >> b;

  std::string judge = "NO";
  if ((r*100+g*10+b)%4==0) {
    judge = "YES";
  }

  std::cout << judge << std::endl;
  return 0;
}
