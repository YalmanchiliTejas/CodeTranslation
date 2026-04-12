#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int,int>pii;
main(){
	int n,x,i;
	for(;scanf("%d%d",&n,&x),n;printf("%d\n",x)){
		vector<pii>v;
		v.push_back(make_pair(x,1));
		for(i=1;i<n;i++){
			pii p=v.back();v.pop_back();
			scanf("%d",&x);
			if(i&1){
				if(x==p.first)
					v.push_back(make_pair(x,p.second+1));
				else{
					pii q=make_pair(0,0);
					if(v.size())q=v.back(),v.pop_back();
					v.push_back(make_pair(x,q.second+p.second+1));
				}
			}else{
				if(x==p.first)v.push_back(make_pair(x,p.second+1));
				else v.push_back(p),v.push_back(make_pair(x,1));
			}
		}
		for(x=i=0;i<v.size();i++){
			if(!v[i].first)x+=v[i].second;
		}
	}
}