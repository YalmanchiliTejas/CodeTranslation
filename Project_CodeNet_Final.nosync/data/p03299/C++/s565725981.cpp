#include<bits/stdc++.h>
const int N=103,M=1e9+7;
using namespace std;
int n,m,a[N],b[N],f[N][N],i,j,tp;
inline int ksm(int t){
	if(t<0)return 1;
	int y=1;long long x=2;
	for(;t;t>>=1)
	t&1?y=y*x%M:0,x=x*x%M;
	return y;
}
inline void trans(int d){
	d=min(d,a[i+1]);
	f[i+1][d]=(f[i+1][d]+
	1ll*ksm(b[a[i]]-b[max(j,a[i+1])])*tp)%M;
}
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",a+i),b[i]=--a[i];
	sort(b,b+n+1),m=unique(b,b+n+1)-b;
	for(i=0;i<n;i++)
	a[i]=lower_bound(b,b+m,a[i])-b;
	f[0][0]=1;
	for(i=0;i<n;i++)
	for(j=0;j<=a[i];j++)
	if(tp=f[i][j])
	trans(j),trans(a[i]);
	printf("%d",f[n][0]);
}