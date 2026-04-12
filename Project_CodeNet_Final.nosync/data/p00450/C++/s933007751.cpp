#include<iostream>
#include<stack>
using namespace std;
int main()
{
  int n;
  for(;cin>>n,n;)
    {
      stack<pair<int,int> > data;
      data.push(make_pair(0,-1));
      for(int i=1;i<=n;i++)
	{
	  int tmp;
	  cin>>tmp;
	  pair<int,int> tt = data.top();
	  data.pop();
	  if(i%2!=0)
	    {
	      if(tt.second==tmp)
		data.push(make_pair(tt.first+1,tmp));
	      else
		{
		  data.push(tt);
		  data.push(make_pair(1,tmp));
		}
	    }
	  else
	      data.push(make_pair(tt.first+1,tmp));
	  //	  for(int xx=0;xx<data.size();xx++)
	  //	    cout<<"<"<<data[xx].first<<" "<<data[xx].second<<"> ";
	  //	  cout<<endl;
	  if(data.size()>1)
	    {
	      pair<int,int> t1 = data.top();
	      data.pop();
	      pair<int,int> t2 = data.top();
	      data.pop();
	      if(t1.second==t2.second)
		data.push(make_pair(t1.first+t2.first,t1.second));
	      else
		{
		  data.push(t2);
		  data.push(t1);
		}
	    }

	}
      int ans=0;
      while(!data.empty())
	{
	  pair<int,int> tt = data.top();
	  data.pop();
	  //	  cout<<tt.first<<" "<<tt.second<<endl;
	  if(tt.second==0)
	    ans+=tt.first;
	}
      cout<<ans<<endl;
    }

}