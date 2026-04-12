#include <bits/stdc++.h>
using namespace std;
int N;
string S;

void print(vector<bool> &vb)
{
  for (int i = 1; i <= N; i++)
  {
    if (vb.at(i))
      cout << 'W';
    else
      cout << 'S';
  }
  cout << endl;
}

void build(vector<bool> &vb)
{
  if (vb[1]) // W
  {
    if (S.at(0) == 'o')
      vb.at(0) = !vb.at(2);
    else
      vb.at(0) = vb.at(2);
  }
  else
  {
    if (S.at(0) == 'o')
      vb.at(0) = vb.at(2);
    else
      vb.at(0) = !vb.at(2);
  }

  for (int i = 2; i <= N; i++)
  {
    if (vb.at(i)) // W
    {
      if (S.at(i - 1) == 'o')
        vb.at(i + 1) = !vb.at(i - 1);
      else
        vb.at(i + 1) = vb.at(i - 1);
    }
    else
    {
      if (S.at(i - 1) == 'o')
        vb.at(i + 1) = vb.at(i - 1);
      else
        vb.at(i + 1) = !vb.at(i - 1);
    }
  }
}

int main()
{
  cin >> N >> S;
  vector<bool> vb(N + 2);
  for (int i = 0; i <= 1; i++)
  {
    for (int j = 0; j <= 1; j++)
    {
      vb[1] = i, vb[2] = j; // 0: S, 1: W
      build(vb);
      if (vb[1] == vb[N + 1] && vb[0] == vb[N])
      {
        print(vb);
        return 0;
      }
    }
  }
  cout << -1 << endl;
}