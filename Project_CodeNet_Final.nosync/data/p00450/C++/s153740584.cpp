#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int,int>pii;
main(){
	int n,x,i,q;
	for(;scanf("%d%d",&n,&x),n;printf("%d\n",x)){
		vector<pii>v;
		v.push_back(make_pair(x,1));
		for(i=1;i<n;i++){
			pii p=v.back();
			scanf("%d",&x);
			if(x==p.first)v.back().second++;
			else if(v.pop_back(),i&1){
				if(q=0,v.size())q=v.back().second,v.pop_back();
				v.push_back(make_pair(x,q+p.second+1));
			}else{
				v.push_back(p),v.push_back(make_pair(x,1));
			}
		}
		for(x=i=0;i<v.size();i++)if(!v[i].first)x+=v[i].second;
	}
}