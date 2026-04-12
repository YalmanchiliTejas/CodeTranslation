#include<iostream>
#include<string>
using namespace std;

int main()
{
  string s;
  for(;cin>>s,s!="#";)
    {
      int c=0;
      bool t;
      for(int i=0;i<s.size();i++)
	{
	  if( string("qwertasdfgzxcvb").find(s[i],0)!= string::npos )
	    {
	      if(i!=0 && !t)
		c++;
	      t=true;
	    }
	  else
	    {
	      if(i!=0 && t)
		c++;
	      t=false;
	    }
	}
      cout<<c<<endl;
    }
}