#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int int64_t
int tot[55]={0},patty[55]={0};
int f(int n,int x){
	if(tot[n]==x)return patty[n];
	if(x<=1)return 0;
	if(x<=1+tot[n-1])return f(n-1,x-1);
	if(x<=2+tot[n-1])return 1+f(n-1,x-2);
	if(x<=2+tot[n-1]+tot[n-1])return f(n-1,tot[n-1])+1+f(n-1,x-tot[n-1]-2);
	else return 2*f(n-1,tot[n-1]);
}
int32_t main(){
	int n,x;cin>>n>>x;
	tot[0]=1;
	for(int i=1;i<=n;++i)tot[i]=2*tot[i-1]+3;
	patty[0]=1;
	for(int i=1;i<=n;++i)patty[i]=2*patty[i-1]+1;
	cout<<f(n,x);
	return 0;
}

