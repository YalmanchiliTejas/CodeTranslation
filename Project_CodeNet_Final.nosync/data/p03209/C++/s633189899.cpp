#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,x;
	cin>>n>>x;
	long long a[n+1],b[n+1];
	a[0]=1;
	b[0]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]*2+1;
		b[i]=b[i-1]*2+3;
	}
	long long ans=0;
	while(x>0){
		if(x==b[n]){
			ans+=a[n];
			x=0;
		}
		else if(x>=b[n]/2+1){
			ans+=a[n-1]+1;
			x-=b[n]/2+1;
		}
		else
		   x--;
		n--;
	}
	cout<<ans<<endl;
	return 0;
}

