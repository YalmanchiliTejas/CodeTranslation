#include <bits/stdc++.h>
using namespace std;

bool acgt(char ch)
{
  char atgc[]="ACGT";
  for(int j=0 ; j<4 ; ++j)
  {
      if(ch==atgc[j])
      {
        return true;
      }
  }
  return false;
}

int main()
{
	int n;
  	cin>>n;
  	int west,mountain;
  	cin>>west;
  	int ans=1;
  	for(int i=1 ; i<n ; ++i)
    {
    	cin>>mountain;
      	ans+=(mountain>=west);
      	west=max(west,mountain);
    }
  	cout<<ans<<endl;
	return 0;
}
