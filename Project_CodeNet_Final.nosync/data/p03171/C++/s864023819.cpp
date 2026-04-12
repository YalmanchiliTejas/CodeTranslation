#include<cstdio>
#include<cstring>
const int MAXN=3010;

int n,a[MAXN];
long long f[MAXN][MAXN];

inline long long max(long long x,long long y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int len=1;len<=n;len++)
		for(int r=1;r<=n;r++){
			int l=r-len+1;
			if(l<1)
				continue;
			f[l][r]=max(a[l]-f[l+1][r],a[r]-f[l][r-1]);
		}
	printf("%lld\n",f[1][n]);
	return 0;
}