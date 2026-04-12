#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
  int n;
  for(;cin>>n,n;)
    {
      vector<int> p;
      for(;n--;)
	{
	  int t;
	  cin>>t;
	  p.push_back(t);
	}
      sort(p.begin(),p.end());
      int sum=0;
      for(int i=1;i<p.size()-1;i++)
	sum+=p[i];
      cout<<sum/(p.size()-2)<<endl;
    }

}