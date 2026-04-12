#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const int N=510;
void out() { puts("-1"); exit(0);}

int n,s[N],t[N],c[N][N],R[N][2],C[N][2];
ull u[N],v[N],ans[N][N];

void solve() {
	for(int k=0;k<64;k++) {
		memset(c,-1,sizeof c);
		memset(R,0,sizeof R);
		memset(C,0,sizeof C);
		for(int i=1;i<=n;i++) {
			int x=u[i]&1;
			if(s[i]^x) for(int j=1;j<=n;j++) c[i][j]=x;
		}
		for(int i=1;i<=n;i++) {
			int x=v[i]&1;
			if(t[i]^x) {
				for(int j=1;j<=n;j++) {
					if(~c[j][i]&&c[j][i]!=x) out();
					c[j][i]=x;
				}
			}
		}
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=n;j++) {
				if((u[i]&1)==(v[j]&1)) c[i][j]=u[i]&1;
				if(c[i][j]==-1) c[i][j]=0;//不确定的先设为0. 
				R[i][c[i][j]]++;
				C[j][c[i][j]]++;
			}
		//由于0的个数饱和所以只用把部分0改成1即可. (针对| 1)
		for(int i=1;i<=n;i++)
			if(s[i]==1&&(u[i]&1)==1&&!R[i][1]) 
				for(int j=1;j<=n;j++)
					if(t[j]==0&&(v[j]&1)==0&&C[j][0]>1) {
						R[i][0]--; C[j][0]--;
						R[i][1]++; C[j][1]++;
						c[i][j]=1;
						break;
					}
		for(int i=1;i<=n;i++)
			if(t[i]==1&&(v[i]&1)==1&&!C[i][1])
				for(int j=1;j<=n;j++)
					if(s[j]==0&&(u[j]&1)==0&&R[j][0]>1) {
						C[i][0]--; R[j][0]--;
						C[i][1]++; R[j][1]++;
						c[j][i]=1;
						break;
					}
		for(int i=1,x;i<=n;i++) {
			if(s[i]&1) {
				if((u[i]&1)&&!R[i][1]) out();
				if(!(u[i]&1)&&R[i][1]) out();
			}
			else {
				if((u[i]&1)&&R[i][0]) out();
				if(!(u[i]&1)&&!R[i][0]) out();
			}
			if(t[i]&1) {
				if((v[i]&1)&&!C[i][1]) out();
				if(!(v[i]&1)&&C[i][1]) out();
			}
			else {
				if((v[i]&1)&&C[i][0]) out();
				if(!(v[i]&1)&&!C[i][0]) out();
			}
			u[i] >>= 1;
			v[i] >>= 1;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans[i][j]|=(ull)c[i][j]<<k;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%llu%c",ans[i][j]," \n"[j==n]);
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	for(int i=1;i<=n;i++) scanf("%llu",&u[i]);
	for(int i=1;i<=n;i++) scanf("%llu",&v[i]);
	solve(); return 0;
}
