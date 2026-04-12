#include <iostream>
#include <vector>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
int const inf =    1000000000;
int const modulo = 1000000007;
int v[1 + nmax];

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b/ 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

std::pair<int,int> solve(int from, int to, int start) {
  int smin = inf;
  for(int i = from; i <= to; i++)
    smin = std::min(smin, v[i]);
  int last = from - 1;
  
  std::pair<int,int> sol;

  for(int i = from; i <= to; i++) {
    if(v[i] == smin) {
      if(last + 1 < i) {
        if(last == from - 1) { 
          sol = solve(last + 1, i - 1, smin);
          sol.first = sol.first * 2 % modulo;
        } else {
          std::pair<int,int> aux = solve(last + 1, i - 1, smin);
          sol.second = (1LL * sol.second * (2LL * aux.first + aux.second) + 1LL * sol.first * aux.second + 1LL * sol.first * aux.first) % modulo;
          sol.first = 1LL * sol.first * aux.first % modulo;
        }
      }
      if(i == from)
        sol = {2, 0};
      else {
        sol = {sol.first, (sol.first + 2LL * sol.second) % modulo};
      }
      last = i;
    }
  }

  if(last + 1 <= to) {
    if(last == from - 1) { 
      sol = solve(last + 1, to, smin);
      sol.first = sol.first * 2 % modulo;
    } else {
      std::pair<int,int> aux = solve(last + 1, to, smin);
      sol.second = (1LL * sol.second * (2LL * aux.first + aux.second) + 1LL * sol.first * aux.second + 1LL * sol.first * aux.first) % modulo;
      sol.first = 1LL * sol.first * aux.first % modulo;
    }
  }

  sol.first = 1LL * sol.first * lgpow(2, smin - start - 1)% modulo;

  return {sol.first, sol.second};
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  std::pair<int,int> sol = solve(1, n, 0);
  std::cout << (sol.first + sol.second) % modulo;
  return 0;
}
