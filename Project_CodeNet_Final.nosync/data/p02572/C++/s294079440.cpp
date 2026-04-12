#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000007],ans,qz[1000007];
const ll N=1000000007;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]%=N;
		qz[i]=a[i];
	}


    for(int i=2;i<=n;i++)
    {
    	qz[i]+=qz[i-1]%N;
    	qz[i]%=N;
    
    }

	for(int i=n;i>=3;i--)
	{
		ans+=((a[i]%N)*(qz[i-1]%N))%N;
	}
	ans+=(a[1]%N)*(a[2]%N);
	ans%=N;
	cout<<ans;
	return 0;
}