#include <iostream>
const int INF = 1001001001;
typedef long long ll;
using namespace std;
ll f(int n, ll x) {
  if (n == 0) return 1;
  ll len = (1LL<<(n+1)) - 3;
  ll num = (1LL<<n) - 1;
  if (x == 1) return 0;
  else if (x <= len + 1) return f(n-1, x-1);
  else if (x == len + 2) return num + 1;
  else if (x <= 2*(len+1)) return num + 1 + f(n-1, x-len-2);
  else return 2*num + 1;
}
 
int main() {
  int n; ll x;
  cin >> n >> x;
  cout << f(n, x) << endl;
}