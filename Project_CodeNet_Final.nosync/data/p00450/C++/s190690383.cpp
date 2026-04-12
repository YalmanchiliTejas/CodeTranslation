#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
int n;
int num[100005];
int main()
{
  while(1){
  vector<P> vec;
  vec.resize(0);
  scanf("%d",&n);
  if(!n) break;
  for(int i=1;i<=n;i++)
    {
      scanf("%d",&num[i]);
    }
  int st=1;
  for(int i=1;i<n;i++)
    {
      if(num[i]!=num[i+1])
    {
      vec.push_back(make_pair(num[i],st));
      st=i+1;
    }
    }
  vec.push_back(make_pair(num[n],st));
  for(int i=0;i<vec.size();i++)
    {
      if(vec[i].second%2==0)
    {
      int w=i;
      while(w>0)
        {
          w--;
          if(vec[w].first!=vec[i].first)
	    {
          vec[w].first=1-vec[w].first;
	    }else
	    {
	      break;
	    }
        }
    }
    }
  int ans=0;
  for(int i=0;i<vec.size();i++)
    {
      if(vec[i].first==0)
    {
      if(i!=vec.size()-1)
        {
          ans+=(vec[i+1].second-vec[i].second);
        }
      else
        {
          ans+=(n+1-vec[i].second);
        }
    }
    }
  printf("%d\n",ans);
  }
  return 0;
}