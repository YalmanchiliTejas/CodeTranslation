//Problem D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;ll k,a[55],b[55];
ll solve(int n,ll k){//printf("%d %lld\n",n,k);
	if(!n||!k)return k;
	if(k<=a[n-1]+1)return solve(n-1,k-1);
	return b[n-1]+1+solve(n-1,k-a[n-1]-2-(k==a[n]));
}
int main(){
    scanf("%d%lld",&n,&k);
	a[0]=b[0]=1;for(int i=1;i<=n;i++)a[i]=3+a[i-1]*2,b[i]=1+b[i-1]*2;
	printf("%lld",solve(n,k));
    return 0;
}