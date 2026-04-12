#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,n) for(int i=a;i<n;i++)
#define M 1000000007
ll power(ll x, ll y, ll p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {   if (y & 1)
        res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
int main()
{
	IOS;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int max=a[0],ans=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]>=max)
		{
			ans++;
			max=a[i];
		}
	}
	cout<<ans;
}
