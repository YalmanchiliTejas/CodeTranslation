#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<bitset>
#define endl "\n"
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int x=0, y=0;
  cin >> n;

  for (int i=1; i <= n; i++)
  {
    x += 800;
    if (i%15 == 0)
    {
      y += 200;
    }
  }
  cout << x - y << endl;

  return 0;
}
