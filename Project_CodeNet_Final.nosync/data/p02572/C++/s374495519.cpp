#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,a[200001],i;
	long long sum=0,sum2=0;
	sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		sum%=1000000007;
	}
	for(i=0;i<n;i++){
		sum-=a[i];
		if(sum<0){
			sum+=1000000007;
		}
		sum2+=a[i]*sum%1000000007;
		sum2%=1000000007;
	}
	printf("%lld\n",sum2);
	return 0;
}