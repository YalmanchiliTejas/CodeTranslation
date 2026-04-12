#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100020];
int f[100020];
signed main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	reverse(a,a+n);
	memset(f,0x3f,sizeof f);
	for(int i=0;i<n;i++){
		int p=upper_bound(f,f+n,a[i])-f;
		f[p]=a[i];
	}
	int ans2=upper_bound(f,f+n,0x3f3f3f3f)-f;
	cout<<ans2<<endl; 
}