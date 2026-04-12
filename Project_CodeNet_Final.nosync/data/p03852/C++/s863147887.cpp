#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef unsigned long long u64;
typedef signed long long l64;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c;
  cin >> c;
  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
  return 0;
}
