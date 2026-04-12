#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W; cin >>H >>W; 
  
  //入れる
  vector<vector<char>> mass(H,vector<char>(W));
  for(int i=0;i<H;i++)
  {
    for(int j=0;j<W;j++)
    {
      cin >>mass.at(i).at(j);
    }    
  }

  //削る
  //縦軸.横の数だけ縦を
  for(int i=0;i<W;i++)
  {
    int count =0;
    for(int j=0;j<H;j++)
    {
    if(mass.at(j).at(i)=='.')count++;
      //xに変える
      if(count==H){
        for(int k=0;k<H;k++)
        {
        mass.at(k).at(i)='x';
        }
      }
    }
  }
  
  //横
  for(int i=0;i<H;i++)
  {
    int count =0;
    for(int j=0;j<W;j++)
    {
    if(mass.at(i).at(j)!='#')count++;
      //xに変える
      if(count==W){
        for(int k=0;k<W;k++)
        {
        mass.at(i).at(k)='x';
        }
      }
    }
  }
  
  for(int i=0;i<H;i++)
  {
    int count=0;
    for(int j=0;j<W;j++)
    {
      if(mass.at(i).at(j)!='x')cout <<mass.at(i).at(j);
      else count++;
      if(j==W-1&&count<W-1)cout <<endl;
    }    
  }
  
}
