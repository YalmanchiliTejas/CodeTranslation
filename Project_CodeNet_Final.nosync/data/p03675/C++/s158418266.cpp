#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int a[N];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n&1){
		for(int i=n;i>=1;i-=2) printf("%d ",a[i]);
		for(int i=2;i<=n-1;i+=2) printf("%d ",a[i]);
	} 
	else{
		for(int i=n;i>=2;i-=2) printf("%d ",a[i]);
		for(int i=1;i<=n-1;i+=2) printf("%d ",a[i]);
	}
	return 0;
}