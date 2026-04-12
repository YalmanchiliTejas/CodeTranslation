#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <time.h>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for (i = 0; i < n; i++)
#define P pair<int, int>

int main()
{
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  vector<int> mx(n);
  mx[0] = h[0];
  for (int i = 1; i < n; i++)
  {
    mx[i] = max(mx[i - 1], h[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (h[i] == mx[i])
    {
      ans++;
    }
  }

  cout << ans << endl;
}
