#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int a[200010];

int main(){
	int i,s;
	scanf("%d",&n);
	for(i = 1; i <= n; i++) scanf("%d",&a[i]);
	for(i = n; i > 0; i -= 2) printf("%d ",a[i]);
	if(n & 1) s = 2; else s = 1;
	for(i = s; i <= n; i += 2) printf("%d ",a[i]);
	return 0;
}