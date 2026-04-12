#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));

#define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);
using namespace std;
vector<int> g[110000];
int UF[110000];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
pair<int,pair<int,int> > e[210000];
long long ret[210000];
int segtree[524288];
int num[110000];
int rev[110000];
int v[210000];
int fi[110000];
int now;
int sz;
void dfs(int a,int b){
	
	num[a]=now;
	rev[now]=a;
	now++;
	fi[a]=sz;
	v[sz++]=num[a];
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		dfs(g[a][i],a);
		v[sz++]=num[a];
	}
}
int query(int a,int b,int c,int d,int e){
	if(d<a||b<c)return 999999999;
	if(c<=a&&b<=d)return segtree[e];
	return min(query(a,(a+b)/2,c,d,e*2),query((a+b)/2+1,b,c,d,e*2+1));
}
void update(int a,int b){
	a+=262144;
	while(a){
		segtree[a]=min(segtree[a],b);
		a/=2;
	}
}
map<pair<int,int>,int> m;
long long val;
int use[210000];
vector<int>ad[110000];
vector<int>del[110000];
int L[210000];
int R[210000];
int C[210000];
set<pair<int,int> >S[110000];
int point[110000];
void dfs2(int a,int b){
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		
		dfs2(g[a][i],a);
		if(S[point[a]].size()<S[point[g[a][i]]].size())swap(point[a],point[g[a][i]]);
		for(set<pair<int,int> > ::iterator it=S[point[g[a][i]]].begin();it!=S[point[g[a][i]]].end();it++){
			S[point[a]].insert(*it);
		}
		S[point[g[a][i]]].clear();
	}
	for(int i=0;i<ad[a].size();i++){
		S[point[a]].insert(make_pair(C[ad[a][i]],ad[a][i]));
	}
	for(int i=0;i<del[a].size();i++){
		S[point[a]].erase(make_pair(C[del[a][i]],del[a][i]));
	}
	
	//printf("%d\n",a);
	if(S[point[a]].size()&&~b){
		ret[m[make_pair(a,b)]]=val-C[m[make_pair(a,b)]]+(*(S[point[a]].begin())).first;
		/*for(set<pair<int,int> > ::iterator it=S[a].begin();it!=S[a].end();it++){
			S[b].insert(*it);
		}
		S[a].clear();*/
	}
	//printf("%d\n",a);
}
 
int main(){
 BEGIN_STACK_EXTEND(128*1024*1024);
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)UF[i]=-1;
	for(int i=0;i<b;i++){
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);
		p--;q--;
		L[i]=p;R[i]=q;C[i]=r;
		e[i]=make_pair(r,make_pair(p,q));
		m[make_pair(p,q)]=m[make_pair(q,p)]=i;
	}
	std::sort(e,e+b);
	int rem=a-1;
	for(int i=0;i<b;i++){
		if(FIND(e[i].second.first)!=FIND(e[i].second.second)){
			g[e[i].second.first].push_back(e[i].second.second);
			g[e[i].second.second].push_back(e[i].second.first);
			val+=e[i].first;
			rem--;
			UNION(e[i].second.first,e[i].second.second);
		}
	}
	//for(int i=0;i<a;i++)std::sort(g[i].begin(),g[i].end());

	if(rem){
		for(int i=0;i<b;i++)printf("-1\n");return 0;
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<g[i].size();j++){
			use[m[make_pair(i,g[i][j])]]=1;
		}
	}
	for(int i=0;i<a;i++)point[i]=i;
	for(int i=0;i<524287;i++)segtree[i]=999999999;
	for(int i=0;i<b;i++)ret[i]=9999999999999999LL;
	for(int i=0;i<b;i++)if(!use[i])ret[i]=val;
	
	dfs(0,-1);
	//printf("1out\n");
	for(int i=0;i<sz;i++)update(i,v[i]);
	//printf("upd\n");
	for(int i=0;i<b;i++){
		if(use[i])continue;
		int at=rev[query(0,262143,min(fi[L[i]],fi[R[i]]),max(fi[L[i]],fi[R[i]]),1)];
	//	printf("%d %d %d\n",L[i],R[i],at);
		if(at!=L[i])ad[L[i]].push_back(i);
		if(at!=R[i])ad[R[i]].push_back(i);
		del[at].push_back(i);
	}
	//printf("2in\n");
	dfs2(0,-1);
//	printf("2out\n");
	for(int i=0;i<b;i++){
		if(ret[i]>999999999999999LL)printf("-1\n");
		else printf("%lld\n",ret[i]);
	}
 END_STACK_EXTEND;
}