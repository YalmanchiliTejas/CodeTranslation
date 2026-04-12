#include<bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;
  
  vector<char> plate(h * w);
  vector<int> w_flag(w);
  vector<int> h_flag(h);
  for (int j = 0; j < h; j ++)
  {
    for (int i = 0; i < w; i ++)
    {
      int pos = j * w + i;
      cin >> plate.at(pos);
      if (plate.at(pos) == '#')
      {
        w_flag.at(i) = true;
        h_flag.at(j) = true;
      }
    }
  }
  
  for (int j = 0; j < h; j ++)
  {
    if (!h_flag.at(j)) continue;
    for (int i = 0; i < w; i ++)
    {
      if (!w_flag.at(i)) continue;
      cout << plate.at(j * w + i);
    }
    cout << endl;
  }
  
  return 0;
}