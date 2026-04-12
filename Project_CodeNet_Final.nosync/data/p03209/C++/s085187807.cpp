#include"bits/stdc++.h"
using namespace std;

vector<long long> l;
vector<long long> p;

long long f(int n, long long x) {
  if (n == 0) {
    if (x > 0) return 1;
    else return 0;
  }
  else if (x <= 1 + l[n - 1]) return f(n - 1, x - 1);
  else return p[n - 1] + 1 + f(n - 1, x - 2 - l[n - 1]);
}

void Main() {
  int n;
  long long x;
  cin >> n >> x;

  l.push_back(1);
  p.push_back(1);

  for (int i = 0; i < n; i++) {
    l.push_back(l[i] * 2 + 3);
    p.push_back(p[i] * 2 + 1);
  }

  cout << f(n, x)<< endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}

