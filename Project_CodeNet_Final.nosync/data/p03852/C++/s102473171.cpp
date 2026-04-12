#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
  char c;
  cin >> c;
  if (c != 'a' && c != 'i' && c != 'u' && c != 'e' && c != 'o') cout << "consonant" << endl;
  else cout << "vowel" << endl;
  return 0;
}
