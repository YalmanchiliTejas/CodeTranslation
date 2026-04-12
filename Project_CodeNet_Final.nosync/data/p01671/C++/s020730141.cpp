#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

struct unifo{
	int n;
	int uni[200005];
	void init(int in){
		n=in;
		rep(i,n)uni[i]=i;
	}
	int find(int p){
		if(uni[p]==p)return p;
		else return (uni[p]=find(uni[p]));
	}
	void mer(int p,int q){
		if(!same(p,q))uni[find(p)]=find(q);
	}
	bool same(int p,int q){
		return find(p)==find(q);
	}
	void out(){
		vector<mp> ps;
		//printf("%d %d\n",i,find(i));
		rep(i,n)ps.push_back(mp(find(i),i));
		sort(ps.begin(),ps.end());
		printf("uni .. %d elem\n{ ",n);
		rep(i,n){
			if(i!=0 && ps[i-1].fir!=ps[i].fir)printf("}\n{ ");
			printf("%d ",ps[i].sec);
		}
		printf("}\n\n");
	}
} uni;

typedef pair<int,mp> mmp;
typedef pair<lli,int> lip;

int n,m;
vector<mp> bvs[100005];

vector<lli> ecs;
vector<mp> eds;
vector<int> ess;
mp vs[100005];

lli sc=0;
lli ans[200005]={};

int dep[100005];

void cdfs(int no,int p,int d){
	dep[no]=d;
	rep(i,bvs[no].size()){
		mp pa = bvs[no][i];
		int to=pa.fir,e=pa.sec;
		if(to==p)continue;
		vs[to]=mp(no,e);
		cdfs(to,no,d+1);
	}
}

int dub[100005][20];

void lcainit(){
	rep(i,n)dub[i][0]=vs[i].fir;
	rep(k,19){
		rep(i,n){
			dub[i][k+1] = dub[dub[i][k]][k];
		}
	}
}

int getlca(int p,int q){
	if(dep[p]<dep[q])swap(p,q);
	irep(i,20){
		if(dep[p]-dep[q]>=(1<<i)){
			p = dub[p][i];
		}
	}
	
	irep(i,20){
		if(dub[p][i]==dub[q][i])continue;
		p = dub[p][i];
		q = dub[q][i];
	}
	
	if(p!=q){
		p = dub[p][0];
		q = dub[q][0];
	}
	return p;
}

void focus(int fr,int to,lli dco){
	for(;;){
		if(uni.same(fr,to))break;
		fr = uni.find(fr);
		mp pa = vs[fr];
		int tf = pa.fir,
			e  = pa.sec;
		ans[e]=sc+dco-ecs[e];
		uni.mer(fr,tf);
		fr = tf;
	}
}


int main(void){
	scanf("%d%d",&n,&m);
	rep(i,m){
		int a,b; lli c;
		scanf("%d%d%lld",&a,&b,&c); a--; b--;
		ecs.push_back(c);
		eds.push_back(mp(a,b));
	}
	
	{
		vector<lip> v;
		rep(i,m)v.push_back(lip(ecs[i],i));
		sort(v.begin(),v.end());
		rep(i,m)ess.push_back(v[i].sec);
	}
	
	{
		uni.init(n+5);	
		vector<int> v;
		int spn=0;
		rep(i,m){
			int e = ess[i];
			int a = eds[e].fir,
				b = eds[e].sec;
			if(uni.same(a,b)){
				ans[e]=-2;
				v.push_back(e);
				continue;
			}
			ans[e]=-1; spn++;
			bvs[a].push_back(mp(b,e));
			bvs[b].push_back(mp(a,e));
			sc += ecs[e];
			uni.mer(a,b);
		}
		if(spn!=n-1){
			rep(i,m)printf("-1\n");
			return 0;
		}
		swap(v,ess);
		rep(i,m){
			if(ans[i]==-2)ans[i]=sc;
		}
	}
	
	cdfs(0,-1,0);
	lcainit();
	uni.init(n+5);	
	
	rep(i,ess.size()){
		int e = ess[i];
		int a = eds[e].fir,
			b = eds[e].sec;
		if(uni.same(a,b))continue;
		
		int anc = getlca(a,b);
		focus(a,anc,ecs[e]);
		focus(b,anc,ecs[e]);
	}
	
	rep(i,m)printf("%lld\n",ans[i]);
	
	return 0;
}