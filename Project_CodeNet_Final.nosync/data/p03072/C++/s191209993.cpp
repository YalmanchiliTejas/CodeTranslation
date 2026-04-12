#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,flag=0;
	cin>> n;
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	a[0]=0;int ans=0;
	for(int i=1;i<=n;i++)
	{
		flag=0;
		for(int j=1;j<=i;j++){
			if(a[i]<a[j]){
				flag=1;
				break;
			}
		}
		if(!flag)ans++;
	}
	cout<<ans<<endl;
	return 0;
}