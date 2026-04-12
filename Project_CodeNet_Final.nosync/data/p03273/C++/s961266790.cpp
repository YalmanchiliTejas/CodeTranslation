#include <bits/stdc++.h>
using namespace std;

bool isnot_allwhite(string str)
{
  bool check = false;
  for(int i = 0; i < str.size(); i++)
  {
    if(str.at(i) == '#')
    {
      check = true;
      break;
    }
  }
  return check;
}

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> vec(0);
  string tmp;
  for(int i = 0; i < H; i++)
  {
    cin >> tmp;
    if(isnot_allwhite(tmp))
      vec.push_back(tmp);    
  }
  H = vec.size();
  vector<int> del(0);
  int count = 0;
  for(int j = 0; j < W; j++)
  {
    bool all_white = true;
    for(int i = 0; i < H; i++)
    {
      if(vec.at(i).at(j - count) == '#')
      {
        all_white = false;
        break;
      }
    }
    if(all_white)
    {
      for(int k = 0; k < H; k++)
        vec.at(k).erase(j - count, 1);
      count++;
    }
  }
  for(int i = 0; i < H; i++)
  {
    for(int j = 0; j < W - count; j++)
      cout << vec.at(i).at(j);
    cout << endl;
  }
}
