#include <vector>
#include <cstdio>
#define M(x,y)push_back(make_pair(x,y))
using namespace std;
main(){
	int n,x,i,q;
	pair<int,int> p;
	for(;scanf("%d%d",&n,&x),n;printf("%d\n",x)){
		vector<pair<int,int> >v;
		v.M(x,1);
		for(i=1;i<n;i++)
			if(p=v.back(),scanf("%d",&x),x==p.first)v.back().second++;
			else if(i&1){
				if(v.pop_back(),q=0,v.size())q=v.back().second,v.pop_back();
				v.M(x,q+p.second+1);
			}else v.M(x,1);
		for(x=i=0;i<v.size();i++)if(!v[i].first)x+=v[i].second;
	}
}