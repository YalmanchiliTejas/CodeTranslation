#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;cin>>n;
	int a[n+1];
	int f[n+1],ans=0;
	f[0]=0;a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=max(a[i-1],f[i-1]);
	}
	for(int i=1;i<=n;i++)if(f[i]<=a[i])ans++;
	cout<<ans<<endl;
}
