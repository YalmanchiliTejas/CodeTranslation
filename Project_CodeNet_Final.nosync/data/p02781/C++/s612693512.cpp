#include <bits/stdc++.h>
using namespace std;
const int MAXN=110;
int n,k,cnt,ans,p[4]={1,9,81,729};
char c[MAXN];
int cx (int x,int k) {
	if (k==0) {return 1;}
	if (k==1) {return x;}
	if (k==2) {return (x*(x-1))/2;}
	if (k==3) {return (x*(x-1)*(x-2))/6;}
	return 0;
}
int main () {
	scanf("%s%d",c+1,&k);
	int n=strlen(c+1);
	for (int i=1;i<=n;i++) {
		if (c[i]!='0') {
			cnt++;
			ans+=cx(n-i,k-cnt+1)*p[k-cnt+1];
			ans+=(c[i]-'0'-1)*cx(n-i,k-cnt)*p[k-cnt];
		}
	}
	printf("%d\n",ans+(cnt==k));
	return 0;
}