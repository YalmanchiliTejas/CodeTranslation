#include <iostream>
#include <vector>
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

vector<vector<long long>> comb(int n, int r)
{
  vector<vector<long long>> v(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++)
  {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++)
  {
    for (int k = 1; k < j; k++)
    {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main()
{
  vector<vector<long long>> v;
  vector<vector<long long>> v1;
  long long ans = 0;
  string n;
  int k;
  cin >> n;
  cin >> k;
  int num = n.length();
  int max = n[0] - '0';
  if (k == 1)
  {
    ans = (num - 1) * 9 + max;
  }
  else if (k == 2)
  {
    v = comb(num, k);
    ans = v[num][k] * 81 - 9 * (num - 1) * (9 - max);
    if (num > 1)
    {
      rep(i, 1, num)
      {
        int m = n[i] - '0';
        if (m == 0)
        {
          ans -= 9;
          continue;
        }
        ans -= (9 - m);
        break;
      }
    }
  }
  else
  {
    int count = 0;

    v = comb(num, k);
    v1 = comb(num - 1, k - 1);
    ans = v[num][k] * 729 - v1[num - 1][k - 1] * 81 * (9 - max);
    if (num > 2)
    {
      rep(i, 1, num)
      {
        int m = n[i] - '0';
        if (count == 0)
        {
          if (m == 0)
          {
            ans -= 9 * (num - i - 1) * 9;
            continue;
          }
          ans -= 9 * (num - i - 1) * (9 - m);
          ++count;
        }
        else
        {
          if (m == 0)
          {
            ans -= 9;
            continue;
          }
          ans -= (9 - m);
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
