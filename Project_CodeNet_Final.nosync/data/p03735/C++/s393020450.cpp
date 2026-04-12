#include<cstdio>
#include<algorithm>
#define MN 101
using namespace std;
int n,m,ma[2],afr[2],mi[2],ifr[2],x[200001],y[200001];
bool cmp(int a,int b){return a>b;}
inline long long _min(long long x,long long y){
	if (x<0) return y;
	if (y<0) return x;
	if (x<y) return x;
	return y;
}
inline long long work(){
	int L,R,i,j;
	int MA,MI;MA=ma[0];MI=mi[1];
	for (i=1;i<=n;i++)
	if (MA==x[i]) break;
	for (j=1;j<=n;j++)
	if (MI==y[j]) break;
	L=y[i]<x[j]?y[i]:x[j];
	R=y[i]>x[j]?y[i]:x[j];
	int LL=L,RR=R;
	for (i=n;i;i--) if ((x[i]>=L&&x[i]<=R)||(y[i]>=L&&y[i]<=R)) continue;else
	if (y[i]>R&&x[i]>R) R=x[i]<y[i]?x[i]:y[i];else if (y[i]<L&&x[i]<L) L=x[i]>y[i]?x[i]:y[i];else if (x[i]-R>L-y[i]) L=y[i];else R=x[i];
	
	for (i=1;i<=n;i++) if ((x[i]>=LL&&x[i]<=RR)||(y[i]>=LL&&y[i]<=RR)) continue;else
	if (y[i]>RR&&x[i]>RR) RR=x[i]<y[i]?x[i]:y[i];else if (y[i]<LL&&x[i]<LL) LL=x[i]>y[i]?x[i]:y[i];else if (x[i]-RR>LL-y[i]) LL=y[i];else RR=x[i];
	return 1LL*(MA-MI)*(R-L<RR-LL?R-L:RR-LL);
}
int main(){
	register int i;
	scanf("%d",&n);
	if (n==1) return puts("0"),0;
	ma[0]=ma[1]=0;
	mi[0]=mi[1]=1e9;
	for (i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		if (x[i]<y[i]) swap(x[i],y[i]);
		if (ma[0]<x[i]) ma[0]=x[i];if (ma[1]<y[i]) ma[1]=y[i];
		if (mi[0]>x[i]) mi[0]=x[i];if (mi[1]>y[i]) mi[1]=y[i];
	}
	printf("%lld\n",_min(work(),1LL*(ma[0]-mi[0])*(ma[1]-mi[1])));
}