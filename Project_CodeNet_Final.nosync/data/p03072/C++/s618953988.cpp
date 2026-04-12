#include <bits/stdc++.h>
using namespace std;
int n;
int a[30];
int main(){
	scanf("%d",&n);
	int tmp = 0,ans = 0;
	for (int i = 0;i < n;++i){
		int x;
		scanf("%d",&x);
		if (x >= tmp){
			ans++;
			tmp = x;
		}
	}
	printf("%d\n",ans);
}
