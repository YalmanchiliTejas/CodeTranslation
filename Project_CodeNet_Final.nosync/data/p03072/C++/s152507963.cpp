#include<cstdio>
#include<algorithm>
using namespace std;
int a[21],n,ans;
int main(){
	scanf("%d",&n);
	ans=n;
	for(register int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<i;j++){
			if(a[j]>a[i]){
				ans--;
				break;
			}
		}
	}
	printf("%d",ans);
}