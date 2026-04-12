#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
	cin>>n;
	ans=n*800;
	ans=ans-(n/15)*200;
	cout<<ans<<endl;
	return 0;
}