#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	int a[114514];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	vector<int>v;
	for(int i=1;i<=a[n-1];i++)if(a[n-1]%i==0)v.push_back(i);
	int ans=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<v.size();j++){
			if(v[j]>=a[i]){
				ans+=v[j]-a[i];
				goto heaven;
			}
		}heaven:;
	}
	cout<<ans<<endl;
	return 0;
}
