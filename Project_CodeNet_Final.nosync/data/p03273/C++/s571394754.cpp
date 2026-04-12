#include <bits/stdc++.h>
using namespace std;

void replace_h(string& s)
{
  for (int i = 0; i < s.size(); ++i) s[i] = 'x';
}
void replace_v(vector<string> &s, int v)
{
  for (int i = 0; i < s.size(); ++i) s[i][v] = 'x';
}

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; ++i) cin >> a[i];
  
  for (int i = 0, k = 0; i < h; ++i, k = 0)
  {
    for (; k < w; ++k)
    {
      if (a[i][k] == '#') break;
    }
    if (k == w) replace_h(a[i]);
  }
  for (int k = 0, i = 0; k < w; ++k, i = 0)
  {
    for (; i < h; ++i)
    {
      if (a[i][k] == '#') break;
    }
    if (i == h) replace_v(a, k);
  }
  
  for (int i = 0; i < h; ++i)
  {
    for (int k = 0; k < w; ++k)
    {
      if (a[i][k] != 'x') cout << a[i][k];
    }
    cout << endl;
  }
}