#include<iostream>
#include<sstream>
#include<vector>

using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}

bool fizz(string s,int n)
{
  if(n%15==0)
    {
      if(s=="FizzBuzz")
	return true;
      else
	return false;
    }
  if(n%3==0)
    {
      if(s=="Fizz")
	return true;
      else
	return false;
    }
  if(n%5==0)
    {
      if(s=="Buzz")
	return true;
      else
	return false;
    }
  if(n==toInt(s))
    return true;
  return false;
}

int main()
{
  int m,n;
  for(;cin>>m>>n,m;)
    {
      vector<int> p;
      p.clear();
      for(int i=1;i<=m;i++)
	p.push_back(i);
      int pp=0;
      for(int i=1;i<=n;i++)
	{
	  string s;
	  cin>>s;
	  if(p.size()==1)
	    continue;
	  if(!fizz(s,i))
	    {
	      //     cout<<p[pp]<<" "<<i<<endl;
	      p.erase(p.begin()+pp);
	    }
	  else 
	    pp++;

	  if(p.size()<=pp)
	    pp=0;
	  
	}

      for(int i=0;i<p.size();i++)
	{
	  cout<<p[i];
	  if(i==p.size()-1)
	    cout<<endl;
	  else
	    cout<<" ";
	}
    }

}