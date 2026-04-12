#include <iostream>
#include <random>
#include <map>
#include <cstring>
#include <stdio.h>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
const int inf=1e9;
const int mod=1e9+7;
typedef long long ll;
typedef vector<int> vi;
typedef string::const_iterator State;
map<string,bool> mp;
string board[15];
int main(int argc,char const* argv[])
{
  string info;
  int sx,sy,gx,gy;
  while(cin >> info && info!="#")
    {
      string board[15]={};
      string ans="";
      int H=0,W=0;
      bool slash=false;
      int dot=0;
      cin >> sy >> sx >> gy >> gx;
      sx--,sy--,gx--,gy--;
      for(int i=0;i<int(info.size());i++)
	{
	  if(info[i]=='/')
	    {
	      H++;
	      if(!slash) slash=true;
	    }
	  else if(info[i]=='b')
	    {
	      board[H]+='b';
	      if(!slash) W++;
	    }
	  else
	    {
	      dot=(info[i]-'0');
	      for(int j=0;j<dot;j++)
		{
		  board[H]+='.';
		}
	      if(!slash) W+=dot;
	    }
	}
      board[sy][sx]='.';
      board[gy][gx]='b';
      for(int i=0;i<=H;i++)
	{
	  int now=0;
	  for(int j=0;j<W;j++)
	    {
	      if(board[i][j]=='.') now++;
	      else if(board[i][j]=='b')
		{
		  if(now>0)
		    {
		      ans+=to_string(now);
		    }
		  ans+='b';
		  now=0;
		}
	    }
	  if(now>0)
	    {
	      ans+=to_string(now);
	    }
	  if(i!=H) ans+='/';
	}
      cout << ans << endl;
    }
  return 0;
}

