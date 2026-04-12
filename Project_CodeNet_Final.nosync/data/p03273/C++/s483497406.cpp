#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int H,W;
  cin >> H >> W;
  char a[H][W];

  for(int i=0;i<H;i++)
    {
      string tmp;      
      cin >> tmp;
      for(int j=0;j<W;j++)
	a[i][j] = tmp[j];
    }


  for(int i=0;i<H;i++)
    {
      bool flg = false;
      for(int j=0;j<W;j++)
	{
	  if( a[i][j] == '#')
	    {
	      flg = true;
	      break;
	    }
	}
      if(!flg)
	{
	  for(int j=0;j<W;j++)
	    a[i][j] = 0;
	}
    }

    for(int j=0;j<W;j++)
    {
      bool flg = false;
      for(int i=0;i<H;i++)
	{
	  if( a[i][j] == '#')
	    {
	      flg = true;
	      break;
	    }
	}
      if(!flg)
	{
	  for(int i=0;i<H;i++)
	    a[i][j] = 0;
	}
    }

  for(int i=0;i<H;i++)
    {
      bool flg=false;
      for(int j=0;j<W;j++)
	{
	  if(a[i][j] != 0)
	    {
	      flg = true;
	      cout << a[i][j];
	    }
	}
      if(flg)
	cout << endl;
    }
      
}
