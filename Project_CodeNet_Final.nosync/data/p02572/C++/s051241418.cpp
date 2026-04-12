#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

#define MOD 1000000007LL
int n;
vector<ll> a;
vector<ll> asum;

int main()
{
  ll ans;

  cin >> n;

  a.resize(n); asum.resize(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  ans=0;
  asum[n-1] = a[n-1];
//printf("asum[%d] = %lld\n", n-1, asum[n-1]);
  for (int i=n-2; i>0; i--) {
    asum[i] = a[i] + asum[i+1];
    asum[i] %= MOD;
//printf("asum[%d] = %lld\n", i, asum[i]);
  }
  for (int i=0; i<n-1; i++) {
//printf("a[%d](%lld) * asum[%d](%lld)\n", i, a[i], i+1, asum[i+1]);
    ans += a[i]*asum[i+1];
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}
