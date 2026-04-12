#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000005],b[1000005];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	int mid=a[(n+1)/2];
	for (int i=1; i<=n; i++)
		if (mid>b[i]){
			if (n%2==1) printf("%d\n",mid);
			else printf("%d\n",a[(n+1)/2+1]);
		}
		else if (mid<b[i]){
			if (n%2==1) printf("%d\n",a[(n+1)/2-1]);
			else printf("%d\n",mid);
		}
		else{
			if (n%2==1) printf("%d\n",a[(n+1)/2-1]);
			else printf("%d\n",a[(n+1)/2+1]);
		}
	return 0;
}