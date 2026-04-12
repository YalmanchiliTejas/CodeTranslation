#include <bits/stdc++.h>
using namespace std;
int n,a[110],ans=1;
int main()
{
    cin>>n;
	for (int i=1;i<=n;i++)
	  cin>>a[i];
	for (int i=2;i<=n;i++)
	{
		bool fla=false;
	    for (int j=1;j<i;j++)
		  if (a[j]>a[i]) {fla=true;break;}
		if (!fla) ans++;
    }
    cout<<ans;
    return 0;
}