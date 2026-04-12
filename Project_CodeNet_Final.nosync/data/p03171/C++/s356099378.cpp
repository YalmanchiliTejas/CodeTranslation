#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "math.h"
#include "cstring"
#include "stack"
#include "queue"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
ll a[3010];
ll dp[3010][3010];
const ll inf = 1e15;

ll rec(int l, int r)//[l,r)
{
  if (dp[l][r] != inf)
  {
    return dp[l][r];
  }
  else
  {
    if (l >= r)
    {
      return dp[l][r] = 0;
    }
    else
    {
      return dp[l][r] = max(a[l] - rec(l + 1, r), a[r - 1] - rec(l, r - 1));
    }
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  fill(dp[0], dp[3009], inf);
  cout << rec(0, n) << "\n";
}