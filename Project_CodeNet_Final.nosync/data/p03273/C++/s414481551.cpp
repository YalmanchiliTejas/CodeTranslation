#include<bits/stdc++.h>

using namespace std;

int main()
{
  int h,w,counth=0,countw=0;
  cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      cin>>a.at(i).at(j);
    //  cout<<a.at(i).at(j);
    }
    //cout<<endl;
  }
  
  for(int i=0;i<h;i++)
  {
    int j;
    for(j=0;j<w;j++)
    {
      if(a.at(i).at(j)=='#')
        break;
    }
    if(j==w)
    {
      counth++;
      for(int k=i;k>0;k--)
      {
        for(int l=0;l<w;l++)
        {
          a.at(k).at(l)=a.at(k-1).at(l);
        }
      }
    }
  }
  
  for(int i=0;i<w;i++)
  {
    int j;
    for(j=0;j<h;j++)
    {
      if(a.at(j).at(i)=='#')
        break;
    }
    if(j==h)
    {
      countw++;
      for(int k=i;k>0;k--)
      {
        for(int l=0;l<h;l++)
        {
          a.at(l).at(k)=a.at(l).at(k-1);
        }
      }
    }
  }
  for(int i=counth;i<h;i++)
  {
    for(int j=countw;j<w;j++)
    {
      cout<<a.at(i).at(j);
    }
    cout<<endl;
  }
}