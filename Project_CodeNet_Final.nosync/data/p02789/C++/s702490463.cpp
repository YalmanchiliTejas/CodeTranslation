#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double getTime() { 
  return clock() / (double) CLOCKS_PER_SEC;
}

void read() {};

template<typename T, typename... Args>
void read(T& a, Args&... args) {
  cin >> a;
  read(args...);
}

void print() {};

template <typename T, typename... Args>
void print(T a, Args... args) {
  cout << a << " \n"[sizeof...(args) == 0];
  print(args...);
}

int main() {
  int n, m; cin >> n >> m;
  if(n == m) {
    puts("Yes");
  }
  else {
    puts("No");
  }
}
