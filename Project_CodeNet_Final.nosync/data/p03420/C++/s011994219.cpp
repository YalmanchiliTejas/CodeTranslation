#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;

int n,k;
ll ans;

int main(){
	int i,j;
	scanf("%d%d",&n,&k);
	if (!k){
		printf("%lld\n",1ll*n*n);
		return 0;
	}
	for (i=k+1;i<=n;i++){
		ans+=1ll*(i-k);
		for (j=i;j<=n;j+=i){
			if (j+k>n) break;
			if (j+i<=n) ans+=1ll*(i-k);
			else ans+=1ll*(n-j-k+1);
		}
	}
	printf("%lld\n",ans);
	return 0;
} 