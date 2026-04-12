#include <bits/stdc++.h>
using namespace std;
long long a,b[200005],c,ans;
int main()
{
	cin>>a;
	for(int i=0;i<a;i++)
	cin>>b[i];
	for(int i=a-2;i>=0;i--)
	{
		c=(c+b[i+1])%1000000007;
		ans=(ans+c*b[i])%1000000007;
	}
	cout<<ans<<endl;
	return 0;
}