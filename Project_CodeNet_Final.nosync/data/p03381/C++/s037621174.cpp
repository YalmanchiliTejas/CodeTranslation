#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector< pi >
const int N=200010;
vi v;
int a[N];
int main()
{
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=x;
		v.pb(x);
	}
	sort(v.begin(),v.end());
	x=n/2-1;
	int y=n/2;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=v[x])
		cout<<v[y]<<"\n";
	else
		cout<<v[x]<<"\n";
	}

	return 0;
}