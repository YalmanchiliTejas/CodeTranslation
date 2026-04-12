#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct data{
	int v,n;
}b[410001];
int i,j,k,n,m,a[410001];
bool cmp1(data x,data y){
	return x.n<y.n;
}
bool cmp2(data x,data y){
	return x.n>y.n;
}
int main(){
	scanf("%d",&n);
	for (i=1,j=k=0;i<=n;i++){
		scanf("%d",&a[i]);b[i].v=a[i];
		if (i&1) b[i].n=++k;else b[i].n=--j;
	}
	//sort(b+1,b+1+n);
	if (n%2==0) sort(b+1,b+1+n,cmp1);else sort(b+1,b+1+n,cmp2);
	for (i=1;i<=n;i++) printf("%d ",b[i].v);
	puts("");
	return 0;
}