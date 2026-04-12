#include <bits/stdc++.h>

using namespace std;

#define fo(i, n)  for(int i = 0; i < n; ++i)

int main()
{
	int n, count = 0, flag = 0;
    cin>> n;
    int h[n];
    fo(i, n)
      cin>>h[i];
    int a = h[0];
  	fo(i, n)
    {
        fo(j, i+1)
        {
	     	if(h[j] <= h[i] && h[i] >= a)
          		flag = 1;
          	else
          	{
          	    flag = 0;
          	    break;
          	}
        }
        if(flag)
            count++;
    }
  	cout<< count;
 	return 0;
}