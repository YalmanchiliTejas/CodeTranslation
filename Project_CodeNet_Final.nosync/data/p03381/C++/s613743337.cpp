#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,x[N],disc[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]),disc[i]=x[i];
	sort(disc+1,disc+n+1);int hzhz=(n+1)/2;
	for (int i=1;i<=n;i++){
		if (x[i]>disc[hzhz]) printf("%d\n",disc[hzhz]);
		else printf("%d\n",disc[hzhz+1]);
	}
	return 0;
}