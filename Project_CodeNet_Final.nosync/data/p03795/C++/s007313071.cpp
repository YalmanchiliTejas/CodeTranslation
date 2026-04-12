#include<bits/stdc++.h>
using namespace std;
int n,ans,temp;
int main()
{
	cin>>n;
	ans+=n*800;
	while(n>=15)
	{
		n-=15;
		temp+=1;
	}
	ans-=temp*200;
	cout<<ans<<endl;
	return 0;
} 