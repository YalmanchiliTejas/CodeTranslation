#include<bits/stdc++.h>
using namespace std;
int n;
int x[25],maxi=-1;
int ans=0;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++) {
		if(x[i]>=maxi) ans++;
		maxi=max(maxi,x[i]);
	}
	cout<<ans;
	return 0;
}
