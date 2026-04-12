#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <cstdio>
#include <climits>
#include <cmath>
#include <array>
#include <functional>
#include <sstream>
#include <list>
#include <set>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const double eps=1e-9;
const int inf=1e9;
typedef pair<int,int> P;
int buckets[256];
typedef string::const_iterator State;
int number(State &begin)
{
  int ret=*begin-'0';
  begin++;
  return ret;
}

int term(State &begin)
{
  int ret=number(begin);
  while(true)
    {
      if(*begin == '*')
	{
	  begin++;
	  ret*=number(begin);
	}
      else
	{
	  break;
	}
    }
  return ret;
}

int expression(State &begin)
{
  int ret=term(begin);
  while(true)
    {
      if(*begin =='+')
	{
	  begin++;
	  ret+=term(begin);
	}
      else
	{
	  break;
	}
    }
  return ret;
}

int rule2(string s)
{
  State begin=s.begin();
  int ret=*begin-'0';
  begin++;
  while(begin!=s.end())
    {
      if(*begin=='+')
	{
	  begin++;
	  ret+=*begin-'0';
	}
      else
	{
	  begin++;
	  ret*=*begin-'0';
	}
      begin++;
    }
  return ret;
}
int main(int argc,char const* argv[])
{
  string s;
  int n;
  int ans1,ans2;
  cin >> s;
  cin >> n;
  State begin=s.begin();
  ans1=expression(begin);
  ans2=rule2(s);
  if(ans1==ans2 && ans1==n)
    {
      cout << 'U' << endl;
    }
  else if(ans1==n)
    {
      cout << 'M' << endl;
    }
  else if(ans2==n)
    {
      cout << 'L' << endl;
    }
  else
    {
      cout << 'I' << endl;
    }
  return 0;
}

