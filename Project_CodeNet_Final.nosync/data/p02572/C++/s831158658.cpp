#include<bits/stdc++.h>
using namespace std;
const int md=1e9+7;
int a[222222];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	long long cnt=0;
	for(int i=0;i<n;i++){
		cnt+=a[i];
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=((cnt-a[i])%md)*a[i]%md;
	}
	if(ans>=md)
		ans%=md;
	if(ans%2==1)
		ans+=md;
	ans/=2;
	cout<<ans<<endl;
	return 0;
}