#include<iostream>
using namespace std;

int main()
{
  int h,w;
  int flag=0;
  cin>>h>>w;
  char a[h][w];
  bool wide[h][w];
  bool height[h][w];

  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      cin>>a[i][j];
      wide[i][j]=false;
      height[i][j]=false;
    }
  }


  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      if(a[i][j]=='#') flag=1;
    }
    if(flag==1)
    {
      for(int j=0;j<w;j++) wide[i][j]=true;
    }
    flag=0;
  }

  for(int j=0;j<w;j++)
  {
    for(int i=0;i<h;i++)
    {
      if(a[i][j]=='#') flag=1;
    }
    if(flag==1)
    {
      for(int i=0;i<h;i++) height[i][j]=true;
    }
    flag=0;
  }


  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      if(wide[i][j])
      {
        if(height[i][j])
        {
          cout<<a[i][j];
          flag=1;
        }
      }
    }
    if(flag==1)cout<<endl;
    flag=0;
  }
}

//   bad

