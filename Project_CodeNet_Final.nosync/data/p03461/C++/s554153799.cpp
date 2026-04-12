#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 105;
const int INF = 1e9;

int A,B;
int d[11][11];
int f[N][N];
int m,ed[N*4][3];
bool bz[11][11];
bool v[N][N];
int n;
int id0[N],id1[N],S,T;

int main(){
	A=get();B=get();
	fo(i,1,A)fo(j,1,B)d[i][j]=get();
	fo(i,0,100)
		fo(j,0,100){
			f[i][j]=-INF;
			fo(x,1,A)
				fo(y,1,B)
				f[i][j]=max(f[i][j],d[x][y]-x*i-y*j);
		}
	int cnt=0;
	S=n=1;
	fo(i,0,100)id0[i]=++n;
	fo(i,0,100)id1[i]=++n;
	T=++n;
	ed[m=1][0]=S;ed[1][1]=id0[0];ed[1][2]=0;
	fo(i,0,99){
		m++;
		ed[m][0]=id0[i];ed[m][1]=id0[i+1];ed[m][2]=-1;
	}
	fo(i,0,99){
		m++;
		ed[m][0]=id1[i+1];ed[m][1]=id1[i];ed[m][2]=-2;
	}
	m++;
	ed[m][0]=id1[0];ed[m][1]=T;ed[m][2]=0;
	while(cnt<A*B){
		bool pd=0;
		fo(i,0,100){
			fo(j,0,100)
			if (!v[i][j]&&f[i][j]<=100&&f[i][j]>=0){
				int ct=0;
				fo(x,1,A)
					fo(y,1,B)
					if (!bz[x][y]&&d[x][y]-x*i-y*j==f[i][j])ct++;
				if (ct){
					pd=1;
					fo(x,1,A)
						fo(y,1,B)
						if (d[x][y]-x*i-y*j==f[i][j])bz[x][y]=1;
					ed[++m][0]=id0[i];ed[m][1]=id1[j];ed[m][2]=f[i][j];
					cnt=cnt+ct;
					break;
				}
				else v[i][j]=1;
			}
			if (pd)break;
		}
		if (!pd)break;
	}
	if (cnt!=A*B)printf("Impossible\n");
	else{
		printf("Possible\n");
		printf("%d %d\n",n,m);
		fo(i,1,m){
			printf("%d %d ",ed[i][0],ed[i][1]);
			if (ed[i][2]==-1)printf("X\n");
			if (ed[i][2]==-2)printf("Y\n");
			if (ed[i][2]>=0)printf("%d\n",ed[i][2]);
		}
		printf("%d %d\n",S,T);
	}
	return 0;
}