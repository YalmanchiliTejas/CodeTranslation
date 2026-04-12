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
const LL MOD = 1e9+7;
const int SIZE = 1e6+5;
const LL INF = 1LL<<60;
const double eps = 1e-4;
const double PI=3.1415926535897932;

char s[9][9];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int main(){
	DRII(h,w);
	REP(i,h)RS(s[i]);
	REP(i,h){
		REP(j,w){
			if(s[i][j]=='.')continue;
			int nn=0;
			REP(d,4){
				int ny=i+dy[d],nx=j+dx[d];
				if(ny<0||ny>=h||nx<0||nx>=w)continue;
				nn+=s[ny][nx]=='#';
			}
			if((i==0&&j==0)||(i==h-1&&j==w-1)){
				if(nn>=2){puts("Impossible");return 0;}
			}
			else{
				if(nn>2){puts("Impossible");return 0;}
			}
		}
	}
	int y=0,x=0;
	REP(i,h+w-2){
		int ny=y+1,nx=x;
		if(ny>=0&&ny<h&&nx>=0&&nx<w){
			if(s[ny][nx]=='#'){
				y++;continue;
			}
		}
		ny=y,nx=x+1;
		if(ny>=0&&ny<h&&nx>=0&&nx<w){
			if(s[ny][nx]=='#'){
				x++;continue;
			}
		}
		puts("Impossible");return 0;
	}
	puts("Possible");
}
