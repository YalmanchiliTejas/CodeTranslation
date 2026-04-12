#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<numeric>
#include<map>
#include<math.h>

using namespace::std;

int main(void)
{
  int n;
  vector<int> s;

  while(cin >> n && n != 0)
    {
      int tempS;
      s.clear();

      for(int i = 0; i < n; i++)
	{
	  cin >> tempS;
	  s.push_back(tempS);
	}

      sort( s.begin() , s.end() );
      int ans=0;
      for(int i = 1; i < n-1; i++)
	{
	  ans+=s[i]; 
	}
      cout << ans/( n - 2 ) << endl;
    }

  return 0;
}