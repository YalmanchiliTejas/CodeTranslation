#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
ll a[3010];
bool prvi;
bool mark[3010][3010];
ll resenje[3010][3010];

ll resi(int l,int d)
{
	if(l>d)
		return 0;
	if(mark[l][d])
		return resenje[l][d];
	mark[l][d]=true;
	if((d-l)%2==prvi)
		resenje[l][d]=max(resi(l,d-1)+a[d],resi(l+1,d)+a[l]);
	else
		resenje[l][d]=min(resi(l,d-1)-a[d],resi(l+1,d)-a[l]);
	return resenje[l][d];
}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	prvi=(n-1)%2;	
	cout<<resi(1,n);
	
	return 0;
}
