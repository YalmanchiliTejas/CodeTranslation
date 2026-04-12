#include<iostream>
using namespace std;
int main(){
  int n,a,b,c,x;
  for(;cin>>n>>a>>b>>c>>x,n;)
    {
      int ans=0;
      int y;
      for(int i=0;i<n;i++)
	{
	  cin>>y;
	  for(int j=0;ans<=10000;j++)
	    {
	      if(x==y)
		{
		  if(i!=n-1)
		    {
		      x=(a*x+b)%c;
		      ans++;
		    }
		  break;
		}
	      x=(a*x+b)%c;
	      ans++;
	    }
	}
      if(ans>10000)
	cout<<"-1"<<endl;
      else
	cout<<ans<<endl;
    }

}