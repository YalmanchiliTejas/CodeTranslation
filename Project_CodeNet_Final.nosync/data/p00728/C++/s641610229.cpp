#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  int kazu=0,sum=0;
  int max,min;

  while(1)
    {
      cin >> n;

      if(n == 0)break;

      sum = 0;

      for(int i = 0;i < n;i++)
	{
	  cin >> kazu;
	  sum += kazu;

	  if(i == 0)
	    {
	      max = kazu;
	      min = kazu;
	    }

	  if(max < kazu) max = kazu;

	  if(kazu < min) min = kazu;
	}
      sum = sum - max - min;

      cout << sum/(n-2) << endl;
    }
}

