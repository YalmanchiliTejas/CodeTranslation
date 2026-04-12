#include <bits/stdc++.h>
using namespace std;

long long *layer,*pate;
long long eatpate(int n,long long x){
	if(x<=n)return 0;
	if(n==0)return 1;
	if(x<=layer[n-1]+1)return eatpate(n-1,x-1);
	return pate[n-1]+1+eatpate(n-1,x-2-layer[n-1]);
}

int main(void){
	int n;
	long long x;
	cin>>n>>x;
	layer=new long long[n+1];
	pate=new long long[n+1];
	layer[0]=1;
	pate[0]=1;
	for(int i=1;i<=n;i++){
		layer[i]=layer[i-1]*2+3;
		pate[i]=pate[i-1]*2+1;
	}
	cout<<eatpate(n,x)<<endl;
	
	delete[] layer;
	delete[] pate;
	return 0;
}
