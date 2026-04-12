#include <bits/stdc++.h>

using namespace std;

int n;
int a[3010];
long long f[3010][3010];
char v[3010][3010];

inline long long dp(int l,int r){
	if(l==r)return f[l][r]=a[l];
	if(v[l][r])return f[l][r];
	v[l][r]=1;
	f[l][r]=max(a[l]-dp(l+1,r),a[r]-dp(l,r-1));
	return f[l][r];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}

	printf("%lld\n",dp(1,n));
	return 0;
}