#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define REP(I,N) for(int I=0;I<N;++I)
#define REPP(I,A,B) for(int I=A;I<B;++I)
#define RI(X) scanf("%d",&X)
#define RII(X,Y) scanf("%d%d",&X,&Y)
#define RIII(X,Y,Z) scanf("%d%d%d",&X,&Y,&Z)
#define DRI(X) int X;scanf("%d",&X)
#define DRII(X,Y) int X,Y;scanf("%d%d",&X,&Y)
#define DRIII(X,Y,Z) int X,Y,Z;scanf("%d%d%d",&X,&Y,&Z)
#define MS0(X) memset(X,0,sizeof(X))
#define MS1(X) memset(X,-1,sizeof(X))
#define RS(X) scanf("%s",X);
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

PII x[100009];
PII v[100009];
int p[100009];

int fp(int x){
	return x==p[x]?x:p[x]=fp(p[x]);
}

void mg(int x,int y){
	x=fp(x),y=fp(y);
	p[x]=y;
}

int main(){
	DRI(n);
	REP(i,n){
		RII(x[i].F,x[i].S);
		v[i]=MP(x[i].F,i);
	}
	sort(v,v+n);
	vector<pair<int,PII> > elist;
	REP(i,n-1)elist.PB(MP(v[i+1].F-v[i].F,MP(v[i].S,v[i+1].S)));
	REP(i,n){
		v[i]=MP(x[i].S,i);
	}
	sort(v,v+n);
	REP(i,n-1)elist.PB(MP(v[i+1].F-v[i].F,MP(v[i].S,v[i+1].S)));
	LL ans=0;
	iota(p,p+n,0);
	sort(ALL(elist));
	for(auto cur:elist){
		if(fp(cur.S.F)==fp(cur.S.S))continue;
		ans+=cur.F;
		mg(cur.S.F,cur.S.S);
	}
	printf("%lld",ans);
}
