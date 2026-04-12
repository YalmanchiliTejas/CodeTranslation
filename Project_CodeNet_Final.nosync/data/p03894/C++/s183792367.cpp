#include <bits/stdc++.h>
using namespace std;

int n,q,a,b,p[100010],p1;
bool f[100010];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		p[i]=i;
	f[1]=true;
	f[2]=true;
	p1=1;
	for(int i=0;i<q;i++){
		scanf("%d%d",&a,&b);
		int t=p[a];
		p[a]=p[b];
		p[b]=t;
		if(a==p1)
			p1=b;
		else if(b==p1)
			p1=a;
		f[p[p1-1]]=f[p[p1]]=f[p[p1+1]]=true;

	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(f[i])ans++;
	printf("%d\n",ans);
	return 0;
}