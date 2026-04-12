#include<bits/stdc++.h>
using namespace std;
int main()
{
int now=-1;int ans=0;
int n; cin>>n;
while (n--)
{
	int tmp;cin>>tmp;
	if (tmp>=now)
	{
		now=tmp;
		ans++;
	}
}
cout<<ans<<endl;
	return 0;
 } 