#include<iostream>
#include<sstream>
using namespace std;

template<class T>inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

int main()
{
  int m;
  cin>>m;
  for(;m--;)
    {
      long long int money;
      cin>>money;
      int year;
      cin>>year;
      int n;
      cin>>n;
      long long int ans=0;
      for(;n--;)
	{
	  int a,c;
	  double b;
	  long long int tmp=money;
	  cin>>a>>b>>c;
	  if(a==0)
	    {
	      int risi=0;
	      for(int i=0;i<year;i++)
		{
		  risi+=tmp*b;
		  tmp-=c;
		}
	      ans=max(ans,risi+tmp);
	    }
	  else
	    {
	      for(int i=0;i<year;i++)
		{
		  tmp+=tmp*b;
		  tmp-=c;
		}
	      ans=max(ans,tmp);
	    }
	}
      cout<<ans<<endl;
    }
}