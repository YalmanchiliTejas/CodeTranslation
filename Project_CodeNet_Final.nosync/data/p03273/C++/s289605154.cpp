#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <math.h>
#include <array>
#include <list>
#include <set>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vp;
int tmpmin=1e9;
int main(int argc,char const* argv[])
{
  int h,w;
  cin >> h >> w;
  int board[105][105];
  vector<string> check(h);
  for(int i=0;i<h;i++)
    {
      cin >> check[i];
    }
  for(int i=0;i<h;i++)
    {
      for(int j=0;j<w;j++)
	{
	  if(check[i][j]=='#')
	    {
	      board[i][j]=1;
	    } 
	  else if(check[i][j]=='.')
	    {
	      board[i][j]=0;
	    } 
	}
    }
  for(int i=0;i<h;i++)
    {
      bool allw=true;
      for(int j=0;j<w;j++)
	{
	  if(board[i][j]==1) allw=false;
	}
      if(allw)
	{
	  for(int j=0;j<w;j++)
	    {
	      board[i][j]=2;
	    }
	}
    }
  for(int j=0;j<w;j++)
    {
      bool allw=true;
      for(int i=0;i<h;i++)
	{
	  if(board[i][j]==1) allw=false;
	}
      if(allw)
	{
	  for(int i=0;i<h;i++)
	    {
	      board[i][j]=2;
	    }
	}
    }
  for(int i=0;i<h;i++)
    {
      bool el=false;
      for(int j=0;j<w;j++)
	{
	  if(board[i][j]==0)
	    {
	      cout << '.';
	      el=true;
	    }
	  else if(board[i][j]==1)
	    {
	      cout << '#';
	      el=true;
	    }
	}
      if(el) cout << endl;
    }
}
