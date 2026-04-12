#include <iostream>
using namespace std;

typedef long long int LLI;

LLI calcNumLayers(int n) {
  return ((1LL << (n + 2)) - 3);
}

LLI calcNumPatties(int n) {
  return ((1LL << (n + 1)) - 1);
}

int main() {
  int n;
  LLI x;
  cin >> n >> x;

  LLI s = 0LL;
  while (1) {
    if (n == 0) {
      s += 1;
      break;
    }
    LLI l = calcNumLayers(n - 1);
    LLI p = calcNumPatties(n - 1);
    if (x == 1) {
      break;
    } else if (x <= l + 1) {
      x -= 1;
    } else if (x == l + 2) {
      s += p + 1;
      break;
    } else if (x <= 2 * l + 2) {
      s += p + 1;
      x -= l + 2;
    } else if (x == 2 * l + 3) {
      s += 2 * p + 1;
      break;
    }
    --n;
  }
  cout << s << endl;

  return 0;
}
