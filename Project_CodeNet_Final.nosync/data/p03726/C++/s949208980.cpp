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
const int MAXN = 1e5+5;
const LL INF = 1LL<<30;
const long double eps = 1e-10;
const double PI=3.1415926535897932;

vector<int> adj[100009];
int mm[100009][2];//parent taken,not taken.

int dp(int x,int f,int p=-1){
	if(mm[x][f]!=-1)return mm[x][f];
	mm[x][f]=0;
	int rangecan[SZ(adj[x])];
	int ccc=0;
	REP(ii,SZ(adj[x])){
		int i=adj[x][ii];
		if(i==p){
			rangecan[ii]=0;
			if(ii)rangecan[ii]+=rangecan[ii-1];
			continue;
		}
		ccc++;
		rangecan[ii]=dp(i,1,x);
		if(ii)rangecan[ii]+=rangecan[ii-1];
	}
	if(f==0){
		return mm[x][f]=(rangecan[SZ(adj[x])-1]==ccc);
	}
	else{
		REP(ii,SZ(adj[x])){
			int i=adj[x][ii];
			if(i==p)continue;
			int midv=dp(i,0,x);
			if(!midv)continue;
			int cv=1;
			if(ii)cv+=rangecan[ii-1];
			cv+=rangecan[SZ(adj[x])-1]-rangecan[ii];
			if(cv==ccc)return mm[x][f]=1;
		}
		return mm[x][f]=0;
	}
}

int main(){
	DRI(n);
	REP(i,n-1){
		DRII(a,b);a--;b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	MS1(mm);
	if(dp(0,1))puts("Second");
	else puts("First");
}
