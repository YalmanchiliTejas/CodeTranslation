#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define _rep(i,m,n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;
const ll mod = 1000000007;

int main() {
  ll a,b,c,x,y; cin >> a >> b >> c >> x >> y;
  ll z = 2 * max(x,y);
  ll sum = 0;
  ll sum_min = INFINITY;
    for (ll i = 0; i <= z; i += 2) {
        ll X = max(x - i / 2, (ll)0);
        ll Y = max(y - i / 2, (ll)0);
        sum = i * c + X * a + Y * b;
        sum_min = min(sum,sum_min);
    }
    print(sum_min);
}
