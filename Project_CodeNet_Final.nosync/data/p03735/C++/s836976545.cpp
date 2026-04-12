#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define RF(x) freopen(x,"r",stdin)
#define WF(x) freopen(x,"w",stdout)
typedef long long LL;
using namespace std;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
const LL MOD = (LL)1e9+7;
const int MAXN = 3e5+5;
const LL INF = 1LL<<60;
const double eps = 1e-9;
const double PI=3.1415926535897932;

LL v[200009][2];
int taken[200009][2];
vector<pair<LL,PII> > dc;

int main(){
	DRI(n);
	if(n==1){puts("0");return 0;}
	REP(i,n){
		scanf("%lld %lld",&v[i][0],&v[i][1]);
		if(v[i][0]>v[i][1])swap(v[i][0],v[i][1]);
	}
	REP(i,n){
		dc.PB(MP(v[i][0],MP(i,0)));
		dc.PB(MP(v[i][1],MP(i,1)));
	}
	sort(ALL(dc));//dc[0].F is BLUE
	LL ans=INF;
	int fb=0,lb=SZ(dc)-1;
	int fr=0,lr=0;
	if(dc[fb].S.F!=dc[lb].S.F){
		REP(i,SZ(dc)){
			if(dc[i].S.F==dc[fb].S.F&&dc[i].S.S!=dc[fb].S.S)fr=i;
			if(dc[i].S.F==dc[lb].S.F&&dc[i].S.S!=dc[lb].S.S)lr=i;
		}
		if(fr>lr)swap(lr,fr);
		//printf("%d %d %d %d\n",fb,lb,fr,lr);
		int r=-1;
		int rtaken=0;//reds taken!
		REPP(l,1,fr+1){
			r=max(l-1,r);
			while(r+1<lr){
				r++;
				if(r==lb)continue;
				taken[dc[r].S.F][dc[r].S.S]=1;
				rtaken+=(!taken[dc[r].S.F][dc[r].S.S^1]);
			}
			while(r+1<SZ(dc)&&rtaken<n){
				r++;
				if(r==lb)continue;
				taken[dc[r].S.F][dc[r].S.S]=1;
				rtaken+=(!taken[dc[r].S.F][dc[r].S.S^1]);
			}
			/*REP(i,n){
				REP(j,2)printf("%d",taken[i][j]);puts("");
			}puts("");*/
			if(rtaken==n){
				ans=min(ans,(LL)(dc[lb].F-dc[fb].F)*(dc[r].F-dc[l].F));
			}
			taken[dc[l].S.F][dc[l].S.S]=0;
			rtaken-=(!taken[dc[l].S.F][dc[l].S.S^1]);
		}
	}
	LL minmax=1<<30,maxmin=-1<<30;
	REP(i,n){
		maxmin=max(maxmin,v[i][0]);
		minmax=min(minmax,v[i][1]);
	}
	ans=min(ans,(LL)(maxmin-dc[0].F)*(LL)(dc.back().F-minmax));
	printf("%lld",ans);
}
