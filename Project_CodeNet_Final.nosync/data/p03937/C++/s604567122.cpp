#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define p pair <int,int>
typedef long long ll;
using namespace std;
int dx[]={1,0};
int dy[]={0,1};
bool stop=true;
bool clear=true;
int main(int argc,char const* argv[])
{
  int h,w,x,y;;
  cin >> h >> w;
  char board[h][w];
  for(int i=0;i<h;i++)
    {
      for(int j=0;j<w;j++)
	{
	  cin >> board[i][j];
	}
    }
  x=0;y=0;
  board[0][0]='.';
  while(0<=x && x<w && 0<=y && y<h)
    {
      stop=true;
      for(int k=0;k<2;k++)
	{
	  if(x+dx[k]>w-1 || y+dy[k]>h-1) continue;
	  if(board[y+dy[k]][x+dx[k]]=='#')
	    {
	      stop=false;
	      board[y+dy[k]][x+dx[k]]='.';
	      x+=dx[k];y+=dy[k];
	      //cout << "now" << ' ' << y << ' ' << x << endl;
	    }
	}
      if(stop == true) break;
      if(x==w-1 && y== h-1) break;
    }
  for(int i=0;i<h;i++)
    {
      for(int j=0;j<w;j++)
	{
	  if(board[i][j] != '.') clear=false;
	}
    }
  if(clear==false || stop==true)
    {
      cout << "Impossible" <<endl;
    }
  else if(clear==true && stop==false)
    {
      cout <<  "Possible" << endl;
    }
  return 0;
}
