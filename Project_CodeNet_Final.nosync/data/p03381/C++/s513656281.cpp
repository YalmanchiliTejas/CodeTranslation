#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[200005];
int ans[200005];
int main() {
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		a[i].first=x;
		a[i].second=i;
	}
	sort(a,a+n);
	for(int i=0;i<n/2;i++){
		ans[a[i].second]=a[n/2].first;
	}
	for(int i=n/2;i<n;i++){
		ans[a[i].second]=a[n/2-1].first;
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<'\n';
	return 0;
}