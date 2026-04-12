#include <cstdio>
#include <iostream>
using namespace std;
int n;
long long a[100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)cin>>a[i];
	long long k=0;
	while(true){
		int t=1;
		for(int i=2;i<=n;++i)
		    if(a[i]>a[t])t=i;
		if(a[t]<n)break;
		long long tmp=a[t]/n;
		a[t]%=n;
		for(int i=1;i<=n;++i)
		    if(i!=t)a[i]+=tmp;
		k+=tmp;
	}
	cout<<k;
}