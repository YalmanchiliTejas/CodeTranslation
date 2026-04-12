#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 200000;
#define Amari 1000000007;
#define p pair <int,int>
using namespace std;
int main(int argc,char const* argv[])
{
  int n;
  long long temp;
  cin >> n;
  vector<long long> ans(n,0);
  if(n % 2 ==0)
    {
      for(int i=0;i<n;i++)
	{
	  cin >> temp;
	  if(i==0)
	    {
	      ans[n/2]=temp;
	    }
	  else
	    {
	      if(i % 2 == 0) ans[n/2+i/2]=temp;
	      else if(i % 2 !=0) ans[n/2-((i+1)/2)]=temp;
	    }
	}
    }
  else
    {
       for(int i=0;i<n;i++)
	{
	  cin >> temp;
	  if(i==0)
	    {
	      ans[n/2]=temp;
	    }
	  else
	    {
	      if(i % 2 != 0) ans[n/2+((i+1)/2)]=temp;
	      else if(i % 2 ==0) ans[n/2-i/2]=temp;
	    }
	}
    }
  for(int i=0;i<n;i++)
    {
      cout << ans[i] << " ";
    }
  return 0;
}
