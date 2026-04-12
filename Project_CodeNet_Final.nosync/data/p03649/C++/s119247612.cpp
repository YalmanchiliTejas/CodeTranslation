#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n;
long long a[55];
long long b[55];
long long c[55];
long long tot;
long long ans;
bool check(){
	for (int i=1;i<=n;i++){
		if (b[i]>=n){
			return false;
		}
	}
	return true;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		long long t=a[i]/n;
		ans+=t;
		b[i]=a[i]-t*n;
		c[i]=t;
		tot+=c[i];
	}
/*	for (int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;*/
	for (int i=1;i<=n;i++){
		b[i]+=tot-c[i];
	}
	while (!check()){
		tot=0;
		for (int i=1;i<=n;i++){
			a[i]=b[i];
		}
		/*for (int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;*/
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for (int i=1;i<=n;i++){
			long long t=a[i]/n;
			ans+=t;
			b[i]=a[i]-t*n;
			c[i]=t;
			tot+=c[i];
		}
		for (int i=1;i<=n;i++){
			b[i]+=tot-c[i];
		}
	}
	cout<<ans;
	return 0;
}