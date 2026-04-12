#include<cstdio>
#include<algorithm>
#define N 600010
using namespace std;

int n;
int a[N],b[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=300000-1,r=300000;
	for(int i=1;i<=n;i++){
		if(i&1){
			b[r]=a[i];
			r++;
		}else{
			b[l]=a[i];
			l--;
		}
	}
	if(n&1){
		reverse(b+l,b+r+1);
	}
	for(int i=l+1;i<=r-1;i++){
		printf("%d ",b[i]);
	}
	return 0;
}