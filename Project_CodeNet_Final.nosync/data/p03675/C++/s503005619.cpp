#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=200005;

int n,x;
int a[N],b[N];

int main(){
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++){
		x=(n-i+2)/2;
		if (n-i+1&1) b[x]=a[i];
		else b[x+i]=a[i];
	}
	for (i=1;i<=n;i++) printf("%d ",b[i]);
	return 0;
}