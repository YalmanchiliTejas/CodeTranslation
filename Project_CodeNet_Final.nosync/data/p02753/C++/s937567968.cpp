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
  string s; cin >> s;
  for(int i = 0; i < 2; i++) {
    if(s[i] != s[i + 1]) {
      print("Yes");
      return 0;
    }
  }
  print("No");
}