#include<bits/stdc++.h>
using namespace std;
int a[100001],d[100001],n;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	int l=1;
	d[1]=a[1];
	for(int i=2; i<=n; i++) {
		if(d[l]>=a[i])d[++l]=a[i];
		else {
			int p=upper_bound(d+1,d+1+l,a[i],greater<int>())-d;
			d[p]=a[i];
		}
	}
	cout<<l;
	return 0; 
}