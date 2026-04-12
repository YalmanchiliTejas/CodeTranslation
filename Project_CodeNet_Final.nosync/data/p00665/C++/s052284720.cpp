#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main(){
  for(int N,M,K,L;scanf("%d %d %d %d",&N,&M,&K,&L),N;){
    map<string,int> m;
    for(int i=0;i<N;i++){
      char name[11];
      int x;
      scanf("%s %d",name,&x);
      m[name]=x;
    }
    map<string,int> idx;
    vector<int> votes;
    for(auto e:m){
      auto s=idx.size();
      idx[e.first]=s;
      votes.push_back(e.second);
    }
    vector<int> fav(M);
    for(auto &e:fav){
      char name[11];
      scanf("%s",name);
      e=idx[name];
    }
    set<int> sfav(begin(fav),end(fav));
    sort(begin(fav),end(fav),[&](int a,int b){
	return (votes[a]!=votes[b])?votes[a]>votes[b]:a<b;
      });
    int l=0,h=min(M,K)+1;
    while(h-l>1){
      int mid=(l+h)/2;
      int vl=0,vh=2e9+9;
      while(vh-vl>1){
	int vm=(vh+vl)/2;
	long long nv=0;
	for(int i=0;i<mid;i++){
	  nv+=max(0,vm-votes[fav[i]]);
	}
	if(nv>L){
	  vh=vm;
	}else{
	  vl=vm;
	}
      }
      auto vmap=votes;
      vector<int> vc(begin(fav),begin(fav)+mid);
      int rl=L;
      for(auto e:vc){
	vmap[e]=max(vl,vmap[e]);
	rl-=max(0,vl-votes[e]);
      }
      sort(begin(vc),end(vc),[&](int a,int b){
	  return (vmap[a]!=vmap[b])?vmap[a]<vmap[b]:a>b;
	});
      for(int i=0;i<rl;i++){
	vmap[vc[i]]++;
      }
      vector<int> rank(N);
      iota(begin(rank),end(rank),0);
      sort(begin(rank),end(rank),[&](int a,int b){
	  return (vmap[a]!=vmap[b])?vmap[a]>vmap[b]:a<b;
	});
      int ri=0;
      for(int i=0;i<K;i++){
	ri+=sfav.count(rank[i]);
      }
      if(ri>=mid){
	l=mid;
      }else{
	h=mid;
      }
    }
    printf("%d\n",l);
  }
}