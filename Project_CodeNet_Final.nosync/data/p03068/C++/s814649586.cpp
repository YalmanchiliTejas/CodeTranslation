#include <iostream>
#include <string>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;

  char c = S[K - 1];
  for (char s : S) {
    if (s == c) {
      cout << s;
    } else {
      cout << '*';
    }
  }
  cout << endl;
}