#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int a[200000];
	int b[200000];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++) b[i] = a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int ans;
		if(b[i]<=a[n/2-1]) ans = a[n/2];
		else ans = a[n/2-1];
		printf("%d\n",ans);
	}
}
