#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int,int > P;

bool Less(P a,P b)
{
  return a.second> b.second;
}
int main()
{
  vector<P> qu;
  int a,b;
  for(;scanf("%d,%d",&a,&b);)
    {
      if(a==0&&b==0)
	break;
      qu.push_back(P(a,b));
    }
  sort(qu.begin(),qu.end(),Less);
  int count=1;
  map<int,int> rank;
  for(int i=0;i<qu.size();i++)
    {
      if(i!=0 && qu[i-1].second!=qu[i].second)
	count++;
      rank[qu[i].first]=count;
    }
  /*
  for(int i=0;i<qu.size();i++)
    {
      printf("%d %d rank:%d\n",qu[i].first,qu[i].second,rank[qu[i].first]);
    }
  */
  for(;~scanf("%d",&a);)
    {
      printf("%d\n",rank[a]);
    }
}