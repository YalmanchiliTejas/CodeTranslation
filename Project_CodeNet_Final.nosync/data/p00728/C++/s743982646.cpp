#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
  int n;
  int po[4000]; 
  while(1)
    {
      cin >> n;
      if(n == 0)break;
      int k;
      for(k=0;k<n;k++)
	{
	  cin >> po[k];
	}
      sort(po,po+k,greater<int>());
      int ans=0;
      for(int i=1;i<k-1;i++)
	{      
	  ans+=po[i];
	}
      cout << floor(ans/(k-2)) << endl;
    }
}