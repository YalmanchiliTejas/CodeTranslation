#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,a[21];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int highest=a[0];
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]>=highest)ans++;
		if(a[i]>highest)highest=a[i];
	}
	cout<<ans<<endl;
    return 0;
}
