#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
using llint = long long int;
int n;
vector<int> vx;
vector<int> vsorted;

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vx.push_back(x);
    vsorted.push_back(x);
  }

  sort(vsorted.begin(), vsorted.end());

  int a, b;
  a = vsorted[n / 2 - 1];
  b = vsorted[n / 2];

  for (int i = 0; i < n; i++)
  {
    if (vx[i] < b)
    {
      cout << b << endl;
    }
    else
    {
      cout << a << endl;
    }
  }
  return 0;
}
