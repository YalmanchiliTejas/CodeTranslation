#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
  int n, ans, max = 0;

  cin >> n;

  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }

  for (int i = 0; i < n; i++)
  {
    if (h[i] >= max)
    {
      max = h[i];
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}

// ...###..