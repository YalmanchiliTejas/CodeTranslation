#include<bits/stdc++.h>
using namespace std;

int main()
{
  while(1)
    {
      int n = 0,mx=-1,mn=1001;
      cin >> n;
      if(n==0)break;
      int avr = 0;
      for(int i=0;i<n;i++)
	{
	  int b;
	  cin >> b;
	  mx =max(b,mx);
	  mn =min(b,mn);
	  avr +=b;
	}
      cout << (avr - mx -mn) /(n -2) << endl;
    }
    


  return 0;
}
