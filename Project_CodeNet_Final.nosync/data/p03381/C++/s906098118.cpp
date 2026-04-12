#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
int a[200005],n,b[200005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int x=b[n/2],y=b[(n/2)+1];
	for(int i=1;i<=n;i++){
		if(a[i]<=x)printf("%d\n",y);
		else printf("%d\n",x);
	}
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    return 0;
}
