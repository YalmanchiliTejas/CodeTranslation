#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5,zqm=1e9+7;
int f[N][100],n,d;
char num[N];

int dp(int x,int y,bool ub) {
	int lim=(ub ? num[x] : 9);
	if(x==n) return lim/d+1-(lim/d*d+y>lim);
	if(!ub&&f[x][y]!=-1) return f[x][y];
	int ret=0;
	for(int i=lim;i>=0;--i) {
		(ret+=dp(x+1,(y-i+d)%d,ub&&i==num[x]))%=zqm;
	}
	if(!ub) f[x][y]=ret;
	//cerr<<x<<' '<<y<<' '<<ub<<' '<<ret<<endl;
	return ret;
}

int main() {
	//freopen("1.in","r",stdin);
	//freopen("1.ans","w",stdout);
	
	scanf("%s%d",num+1,&d);
	n=strlen(num+1);
	for(int i=1;i<=n;++i) num[i]-=48;
	memset(f,255,sizeof(f));
	printf("%d\n",(dp(1,0,1)+zqm-1)%zqm);
	
	return 0;
}
