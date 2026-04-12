#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,x,a[51],b[51],sum,l;

int dfs(int l,int r,int B){
	if(r<=x)return a[B];
	if(x<l)return 0;
	int m=(l+r)/2;
	return dfs(l+1,m-1,B-1)+dfs(m,m,0)+dfs(m+1,r-1,B-1);
}

signed main(){
	cin>>n>>x;
	x--;
	a[0]=1;
	b[0]=1;
	a[1]=3;
	b[1]=5;
	for(int i=2;i<=50;i++){
		a[i]=a[i-1]*2+1;
		b[i]=b[i-1]*2+3;
	}
	cout<<dfs(0,b[n]-1,n)<<endl;
}
