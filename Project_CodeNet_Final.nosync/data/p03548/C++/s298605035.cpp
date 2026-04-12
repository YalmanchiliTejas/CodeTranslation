#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	int a,b,c;
	cin>>a>>b>>c;
	int len=a-2*c+c;
	int ans=len/(b+c);
	cout<<ans<<endl;
	return 0;
}