#include<bits/stdc++.h>
using namespace std;
int main()
{
  int H,W,i,j,count=0;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      cin >> a.at(i).at(j);
    }
  }
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      if(a.at(i).at(j)=='.')
        count++;
    }
    if(count==W)
      for(j=0; j<W; j++)
        a.at(i).at(j)='%';
    count=0;
  }
  count=0;
  for(i=0; i<W; i++){
    for(j=0; j<H; j++){
      if(a.at(j).at(i)=='.' || a.at(j).at(i)=='%')
        count++;
    }
    if(count==H)
      for(j=0; j<H; j++)
        a.at(j).at(i)='%';
    count=0;
  }
  count=0;
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      if(a.at(i).at(j)!='%')
        cout << a.at(i).at(j);
    }
    for(j=0; j<W; j++){
      if(a.at(i).at(j)=='%')
        count++;
    }
    if(count!=W)
      cout << endl;
    count=0;
  }
}
