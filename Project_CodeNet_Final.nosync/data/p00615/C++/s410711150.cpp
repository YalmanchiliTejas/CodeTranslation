#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n,m;
  for(;cin>>n>>m,n||m;)
    {
      int data[m+n];
      for(int i=0;i<m+n;i++)
	cin>>data[i];
      sort(data,data+n+m);
      int ans=0;
      int now=0;
      for(int i=0;i<m+n;i++)
	{
	  ans=max(ans,data[i]-now);
	  now=data[i];
	}
      cout<<ans<<endl;
    }


}