#include<cstdio>
#include<algorithm>

#define	rep(i,n)	for(int i=0;i<n;i++)

using namespace std;

int main(){
	for(int m,n;scanf("%d%d",&m,&n),m||n;){
		int a[20001];
		rep(i,m+n)	scanf("%d",a+i);
		a[m+n]=0;

		sort(a,a+m+n+1);

		int dmax=0;
		rep(i,m+n)	dmax=max(dmax,a[i+1]-a[i]);
		printf("%d\n",dmax);
	}

	return 0;
}