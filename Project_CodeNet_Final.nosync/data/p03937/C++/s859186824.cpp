#include<bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h+2, vector<char>(w+2));
  int i, j;
  for(i = 0; i < h+2; i++)
  {
    for(j = 0; j < w+2; j++)
    {
      if(i == 0 || j == 0 || i == h+1 || j == w+1)
      {
        a.at(i).at(j) = '.';
      }
      else
      {
        cin >> a.at(i).at(j);
      }
    }
  }
  int plax = 1;
  int play = 1;
  int sw = 0;
  while(sw == 0)
  {
    a.at(play).at(plax) = '.';
    bool allvisit = true;
    for(i = 1; i <= h; i++)
    {
      for(j = 1; j <= w; j++)
      {
        if(a.at(i).at(j) == '#')
        {
          allvisit = false;
        }
      }
    }
    if(allvisit) 
    {
      sw = 1;
      break;
    }
    else if(!allvisit && play == h && plax == w) 
    {
      sw = -1;
      break;
    }
    if(a.at(play+1).at(plax) == '#')
    {
      play++;
    }
    else if(a.at(play).at(plax+1) == '#')
    {
      plax++;
    }
    else
    {
      sw = -1;
      break;
    }
  }
  if(sw == 1) cout << "Possible" << endl;
  else if(sw == -1) cout << "Impossible" << endl;
}