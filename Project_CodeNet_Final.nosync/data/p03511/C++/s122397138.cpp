#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,l1,l2;
string s,t,ans="}",cur,now;
int main()
{
	cin>>n>>s>>t;
	if (s+t<t+s) swap(s,t);
	l1=s.length();l2=t.length();
	for (i=0;i*l1<=n;i++)
	{
		if ((n-i*l1)%l2==0)
		{
			while (now.length()+i*l1<n) now+=t;
			now+=cur;
			ans=min(ans,now);
			cout<<ans;
			return 0; 
		}
		cur+=s;
	}
	cout<<ans;
	return 0;
}