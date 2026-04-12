#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main() {
	
	scanf("%d",&n);
	
	int maxx=0;
	for(int i=1;i<=n;i++) {
		int x;
		scanf("%d",&x);
		if (x>=maxx) ans++,maxx=x;
	}
	
	printf("%d",ans);
	return 0;
}