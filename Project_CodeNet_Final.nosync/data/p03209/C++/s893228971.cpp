#include<cstdio>
typedef long long ll;
ll a[55],b[55];
ll work(int n,ll k){
	if(!k)return 0;
	if(!n)return 1;
	if(k==b[n])return a[n];
	k--;
	if(k<=b[n-1])return work(n-1,k);
	else return a[n-1]+1+work(n-1,k-b[n-1]-1);
}
int main(){
	int n,i;
	ll k;
	scanf("%d%lld",&n,&k);
	a[0]=b[0]=1;
	for(i=1;i<=n;i++){
		a[i]=a[i-1]*2+1;
		b[i]=b[i-1]*2+3;
	}
	printf("%lld\n",work(n,k));
	return 0;
}