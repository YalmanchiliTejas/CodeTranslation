#include<algorithm>
#include<stdio.h>
using namespace std;
typedef long long ll;
const int P=1e9+7,N=105;
inline int fpow(int a,int t){
	static int r;
	for(r=1;t;t>>=1,a=(ll)a*a%P)if(t&1)r=(ll)r*a%P;
	return r;
}
int n,m,res,h[N],v[N],f[N][N];
inline void inc(int&x,int y){x+=y;x<P?:x-=P;}
int main(){
	int i,j,k,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",h+i),v[i]=h[i];
	sort(v+1,v+n+1),m=unique(v+1,v+n+1)-v-1;
	for(i=1;i<=n;i++)h[i]=lower_bound(v+1,v+m+1,h[i])-v;
	for(i=j=1;j<=h[i];j++)f[i][j]=(ll)2*(fpow(2,v[j]-v[j-1]-(j==1))-1)*fpow(2,v[h[i]]-v[j])%P;
	f[i][h[i]+1]=2;
	for(i=2;i<=n;i++){
		for(j=1;j<=h[i-1];j++)inc(f[i][min(j,h[i]+1)],f[i-1][j]);
		if(h[i]>h[i-1]){
			t=fpow(2,v[h[i]]-v[h[i-1]]);
			for(j=1;j<=h[i-1];j++)f[i][j]=(ll)f[i][j]*t%P;
			for(j=h[i-1]+1;j<=h[i];j++)f[i][j]=(ll)f[i-1][h[i-1]+1]*2*(fpow(2,v[j]-v[j-1])-1)%P*fpow(2,v[h[i]]-v[j])%P;
		}else (f[i][h[i]+1]<<=1)%=P;
		inc(f[i][h[i]+1],f[i-1][h[i-1]+1]*2%P);
	}
	for(i=1;i<=m+1;i++)inc(res,f[n][i]);
	printf("%d\n",res);
}