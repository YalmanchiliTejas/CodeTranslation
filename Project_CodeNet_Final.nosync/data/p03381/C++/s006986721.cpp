#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read(){
	int ret=0,p=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-') p=-1;ch=getchar();}
	while (ch>='0' && ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*p;
}
struct str{
	int a,b;
}a[200000+3];
int n;
int ans[200000+3];
inline bool cmp(str a,str b){
	return a.a<b.a;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i].a=read();a[i].b=i;
	}
	sort(a+1,a+n+1,cmp);
	int t=n/2;
	for (int i=1;i<=t;i++){
		ans[a[i].b]=a[t+1].a;
	}
	for (int i=t+1;i<=n;i++){
		ans[a[i].b]=a[t].a;
	}
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}