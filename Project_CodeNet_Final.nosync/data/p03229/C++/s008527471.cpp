#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
long long sum[maxn];
int a[maxn];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		sum[0]=a[0];
		for(int i=1;i<n;i++)
			sum[i]=sum[i-1]+a[i];
		long long ans;
		if(n&1){
			if(n==3)
				ans = max(abs(2*a[2]-a[1]-a[0]), abs(2*a[0]-a[1]-a[2]));
			else
				ans = max(abs(2*(sum[n-1]-sum[n/2])-2*(sum[n/2-2])-(a[n/2]+a[n/2-1])), abs(2*(sum[n-1]-sum[n/2+1])-2*(sum[n/2-1])+(a[n/2]+a[n/2+1])));
		}
		else
			ans =abs(2*(sum[n-1]-sum[n/2])-2*(sum[n/2-2])+abs(a[n/2]-a[n/2-1]));
		printf("%lld\n",ans);
	}
}