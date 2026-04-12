#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char ch; cin>>ch;
			cnt+=(ch=='#'?1:0);
		}
	cout<<((cnt+1==n+m)?"Possible\n":"Impossible\n");
}

