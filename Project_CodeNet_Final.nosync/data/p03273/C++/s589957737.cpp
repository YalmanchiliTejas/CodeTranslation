#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>

#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())

#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
  ll H, W;

  cin >> H >> W;

  string str[H];
  for (int i = 0; i < H; i++)
  {
    cin >> str[i];
  } // i

  int markx[W];
  int marky[H];
  for (int i = 0; i < H; i++)
  {
    bool comp = true;
    for (int j = 0; j < W; j++)
    {
      if (str[i][j] == '#')
      {
        comp = false;
        break;
      }
    }
    if (comp)
      marky[i] = 1;
    else
      marky[i] = 0;
  } // i

  for (int j = 0; j < W; j++)
  {
    bool comp = true;
    for (int i = 0; i < H; i++)
    {
      if (str[i][j] == '#')
      {
        comp = false;
        break;
      }
    }
    if (comp)
      markx[j] = 1;
    else
      markx[j] = 0;
  } // i

  for (int i = 0; i < H; i++)
  {
    if (marky[i] == 1)
      continue;
    for (int j = 0; j < W; j++)
    {
      if (markx[j] == 1)
        continue;
      cout << str[i][j];
    } // i
    cout << endl;
  }

  return 0;
}
