#include <stdio.h>
#include <iostream>
#define Re register int

int N,A[3005];
long long s[3005],f[3005][3005];

template <typename T> inline void read(T &var)
{
	T x=0; int w=0; char ch=0;
	while (!isdigit(ch)) w|=ch=='-',ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	var=w?-x:x;
}
long long Solve(int l,int r)
{
	if (f[l][r]) return f[l][r];
	f[l][r]=s[r]-s[l-1]-std::min(Solve(l+1,r),Solve(l,r-1));
	return f[l][r];
}
int main(int argc, char const *argv[])
{
	read(N); for (Re i=1; i<=N; ++i) read(A[i]),f[i][i]=A[i],s[i]=s[i-1]+A[i];
	if (N==1) {printf("%d\n",A[1]); return 0;}
	printf("%lld\n",Solve(1,N)-std::min(Solve(1,N-1),Solve(2,N)));
	//for (Re i=1; i<=N; ++i)
	//	for (Re j=i; j<=N; ++j)
	//		printf("%d %d f=%d\n",i,j,f[i][j]);
	return 0;
}