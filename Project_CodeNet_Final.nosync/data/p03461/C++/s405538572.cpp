#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<iomanip>
#include<utility>
using namespace std;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define rg register
#define il inline
#define lch(x) ((x)<<1)
#define rch(x) ((x)<<1^1)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep0(i,n) for(register int i=0;i<(n);++i)
#define per0(i,n) for(register int i=(n)-1;i>=0;--i)
#define rep(i,st,ed) for(register int i=(st);i<=(ed);++i)
#define per(i,ed,st) for(register int i=(ed);i>=(st);--i)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double dbl;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> il T qmin(const T &a,const T &b){return a<b?a:b;}
template<typename T> il T qmax(const T &a,const T &b){return a>b?a:b;}
template<typename T> il void getmin(T &a,const T &b){if(a>b) a=b;}
template<typename T> il void getmax(T &a,const T &b){if(a<b) a=b;}
il void fileio(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int inf=(int)1e9+7;
const ll linf=(ll)1e17+7;
const int N=12,M=1000006;

int d[N][N],a,b;
int x[M],y[M],c[M],m;
int mx[101][101];
bool used[101][101];

il void add(int xx,int yy,int cc){
	++m;
	x[m]=xx,y[m]=yy,c[m]=cc;
}

int main(){
//	fileio("test");
	scanf("%d%d",&a,&b);
	rep(i,1,a) rep(j,1,b) scanf("%d",d[i]+j);
	rep0(x,101) rep0(y,101){
	//	mx[x][y]=-inf;
		rep(i,1,a) rep(j,1,b){
			getmax(mx[x][y],d[i][j]-i*x-j*y);
		}
	}
/*	rep0(i,3){
		rep0(j,3) cerr<<mx[i][j]<<" ";
		cerr<<endl;
	}*/
	int s=201,t=202;
	add(s,1,inf+1);
	rep(i,1,99) add(i,i+1,inf+1);
	add(101,t,inf+2);
	rep(i,101,199) add(i+1,i,inf+2);
	rep(i,1,a) rep(j,1,b){
		bool flag=false;
		int idx,idy;
		rep0(x,101){
			rep0(y,101){
				if(d[i][j]-i*x-j*y==mx[x][y]){
					idx=x,idy=y;
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) return puts("Impossible"),0;
		if(used[idx][idy]) continue;
		used[idx][idy]=true;
		add(!idx?s:idx,!idy?t:idy+100,mx[idx][idy]);
	}
	puts("Possible");
	printf("202 %d\n",m);
	rep(i,1,m){
		if(c[i]<=inf) printf("%d %d %d\n",x[i],y[i],c[i]);
		else printf("%d %d %c\n",x[i],y[i],c[i]==inf+1?'X':'Y');
	}
	printf("%d %d\n",s,t);
	return 0;	
} 