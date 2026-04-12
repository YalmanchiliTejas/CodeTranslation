#include <iostream>

using namespace std;

int main() {
  int N;
  char s[256];
  int K;
  
  cin >> N;
  cin >> s;
  cin >> K;
  char c = s[K - 1];
  for (int i = 0; i < N; ++i) cout << (s[i] == c ? c : '*');
  cout << endl;
}