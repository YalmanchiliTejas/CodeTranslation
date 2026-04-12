#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
struct C{
  char s[11];
};
pair<C,int> a[100000];
struct pi{
  bool operator()(const pair<C,int>& p,const pair<C,int>& q){
    return strcmp(p.first.s,q.first.s)<0;
  }
  bool operator()(const pair<int,int>& p,const pair<int,int>& q){
    if(0){
    }else if(p.second>q.second){
      return 1;
    }else if(p.second<q.second){
      return 0;
    }else{
      return strcmp(a[p.first].first.s,a[q.first].first.s)<0;
    }
  }
  bool operator()(const pair<C,int>& p,const char q[]){
    return strcmp(p.first.s,q)<0;
  }
};
int main(){
  int i;
  int n,m,k,l;
  while(scanf("%d%d%d%d",&n,&m,&k,&l),n||m||k||l){
    for(i=0;i<n;++i)
      scanf("%s%d",a[i].first.s,&(a[i].second));
    sort(a,a+n,pi());
    pair<int,int> b[100000];
    for(i=0;i<n;++i)
      b[i]=make_pair(i,a[i].second);
    sort(b,b+n,pi());
    int c[100000],d[100000];
    for(i=0;i<n;++i)
      d[i]=i;
    for(i=0;i<m;++i){
      char s[11];
      scanf("%s",s);
      int p=lower_bound(a,a+n,s,pi())-a;
      c[i]=lower_bound(b,b+n,make_pair(p,a[p].second),pi())-b;
      d[c[i]]=-1;
    }
    sort(c,c+m);
    remove(d,d+n,-1);
    int mn=lower_bound(c,c+m,k)-c,mx=min(k,m)+1;
    for(;mx-mn>1;){
      int sm=0;
      for(i=0;i<(mn+mx)/2&&sm<=l;++i){
	if(0){
	}else if(b[c[i]].second>b[d[k-(mn+mx)/2]].second){
	}else if(b[c[i]].second<b[d[k-(mn+mx)/2]].second){
	  if(strcmp(a[b[c[i]].first].first.s,a[b[d[k-(mn+mx)/2]].first].first.s)<0){
	    sm+=b[d[k-(mn+mx)/2]].second-b[c[i]].second;
	  }else{
	    sm+=b[d[k-(mn+mx)/2]].second-b[c[i]].second+1;
	  }
	}else{
	  if(c[i]>d[k-(mn+mx)/2]){
	    ++sm;
	  }
	}
      }
      if(sm>l)
	mx=(mn+mx)/2;
      else
	mn=(mn+mx)/2;
    }
    printf("%d\n",mn);
  }
  return 0;
}