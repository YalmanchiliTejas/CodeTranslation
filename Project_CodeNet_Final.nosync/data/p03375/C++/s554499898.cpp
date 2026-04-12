#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

const int N=3e3+5;

int n,Mo,C[N][N],s[N][N],pw[N],pw2[N*N];

int pwr(int x,int y) {
	int z=1;
	for(;y;y>>=1,x=(ll)x*x%Mo)
		if (y&1) z=(ll)z*x%Mo;
	return z;
}

int main() {
	scanf("%d%d",&n,&Mo);
	fo(i,0,n) {
		C[i][0]=1;
		fo(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mo;
	}
	s[0][0]=1;
	fo(i,1,n+1) {
		fo(j,1,i) {
			s[i][j]=s[i-1][j-1];
			(s[i][j]+=(ll)s[i-1][j]*j%Mo)%=Mo;
		}
	}
	int p=1;
	fo(i,0,n) {
		pw[i]=pwr(2,p)%Mo;
		p=(p<<1)%(Mo-1);
	}
	pw2[0]=1;fo(i,1,n*n) pw2[i]=(pw2[i-1]<<1)%Mo;
	int ans=0;
	fo(j,0,n) {
		int ret=0;
		fo(i,0,j) (ret+=(ll)s[j+1][i+1]*pw2[(n-j)*i]%Mo*pw[n-j]%Mo)%=Mo;
		(ans+=(ll)(j&1?-1:1)*ret*C[n][j]%Mo)%=Mo;
	}
	printf("%d\n",(ans+Mo)%Mo);
	return 0;
}