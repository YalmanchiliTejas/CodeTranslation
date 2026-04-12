#include <bits/stdc++.h>
typedef long long int lld;
typedef unsigned long long int llu;
#define INF (long long int)(9223372036854775807)
#define IINF (int)(2147483647)

using namespace std;
int main(void) {
  char a, b, c;
  cin >> a >> b >> c;
  cout << (a == b && b == c ? "No" : "Yes") << "\n";
}