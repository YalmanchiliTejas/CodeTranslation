#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack> 

using namespace std;

const int maxn=1e5+5;

int fa[maxn],a[maxn],b[maxn];
pair<int,int>sx[maxn],sy[maxn];

int find(int x)
{     
      return x==fa[x]?x:fa[x]=find(fa[x]);
} 
int un(int x,int y)
{     
      x=find(x);
      y=find(y);
	  if(x==y)
	    return 0;
	  fa[x]=y;
	  return 1;
}
int minn(int x,int y)
{     
      return min(abs(a[x]-a[y]),abs(b[x]-b[y]));
}
int main()
{     
      int n,m,j,i,k;
      cin>>n;
      for(i=0;i<n;++i){
      	cin>>a[i]>>b[i];
      	fa[i]=i;
      	sx[i]=make_pair(a[i],i);
      	sy[i]=make_pair(b[i],i);
		  }
	  
      sort(sx,sx+n);
      sort(sy,sy+n);
      
      set<pair<int,pair<int,int> > >st;
      
      for(i=0;i<n-1;++i){
      	st.insert(make_pair(minn(sx[i].second,sx[i+1].second),
		  make_pair(sx[i].second,sx[i+1].second)));
      	st.insert(make_pair(minn(sy[i].second,sy[i+1].second),
		  make_pair(sy[i].second,sy[i+1].second)));
		  }
	  
      int res=0;
      while((int)st.size()){
	    for(set<pair<int,pair<int,int> > >::iterator it=st.begin();it!=st.end();it++){
		   	st.erase(it);
		   	int u=(*it).second.first;
		   	int v=(*it).second.second;
		   	res+=un(u,v)*minn(u,v);
			   }
			}
	  
	  cout<<res<<endl;
	  
	  return 0;
}
