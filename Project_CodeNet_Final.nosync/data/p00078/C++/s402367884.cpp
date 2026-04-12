#include<iostream>
#include<cassert>
#include<iomanip>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;


void draw(int n)
{
  int G[n][n];
  rep(i,n)rep(j,n)G[i][j] = 0;
  int x = n/2;
  int y = (int)(n/2) + 1;
  int px,py;
  rep(i,n*n)
    {

      assert(G[y][x] == 0);
      G[y][x] = i+1;
      if(i == n*n-1)break;
      px = x,py = y;
      x++,y++;
      if(x >= n)x = (x-n);
      if(y >= n)y = (y-n);
      if(G[y][x] != 0)
	{
	BACK:; 
	  x--,y++;
	  if(x < 0)x = n + x;
	  if(y >= n)y = y-n;
	  if(G[y][x] != 0)goto BACK;
	}

    }
  rep(i,n)
    {
      rep(j,n)
	{
	  cout << setw(4) << G[i][j];
	}
      cout << endl;
    }
}

int main()
{
  int n;
  while(cin >> n,n)draw(n);
  return 0;
}