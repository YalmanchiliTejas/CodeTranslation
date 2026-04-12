#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int a[200005],n,b[200005];
map<int,int>__rank;
int main(){
	//freopen("c.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=n;i>=1;--i){
		__rank[b[i]]=i;
	}
	for(int i=1;i<=n;++i){
		printf("%d\n",__rank[a[i]]<=n/2 ? b[n/2+1] : b[n/2]);
	}
	return 0;
}