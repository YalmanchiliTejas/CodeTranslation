#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  int a[n];
  
  for(int i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  sort(a, a + n);
  ll sum1 = 0;
  ll sum2 = 0;
  int b[n];
  int m = (n - 1) / 2;
  b[0] = a[m];
  int bi = 1;
  int l = 0;
  int r = n - 1;

  while(r > m || l < m) {
    if(l < m) b[bi++] = a[l++];
    if(r > m) b[bi++] = a[r--];
  }
  for(int i = 1; i < n; i++)
  {
    sum1 += abs(b[i] - b[i - 1]);
  }

  b[0] = a[m];
  bi = 1;
  l = 0;
  r = n - 1;
  while(r > m || l < m) {
    if(r > m) b[bi++] = a[r--];
    if(l < m) b[bi++] = a[l++];
  }
  for(int i = 1; i < n; i++)
  {
    sum2 += abs(b[i] - b[i - 1]);
  }
  cout << max(sum1, sum2) << endl;
  


  return 0;
}
