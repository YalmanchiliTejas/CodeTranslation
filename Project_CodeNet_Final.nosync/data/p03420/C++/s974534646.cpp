#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n, k;

int main()
{
  cin >> n >> k;
  
  ll res = 0;
  for(int i = k + 1; i <= n; i++)
  {
    res += (n / i) * (i - k);
    if(k == 0)
    {
      res += n % i;
    }
    else if(n % i >= k)
    {
      res += n % i - k + 1;
    }
  }
  cout << res << endl;
  
  return 0;
}