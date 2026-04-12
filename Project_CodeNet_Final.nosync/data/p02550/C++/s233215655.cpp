#include<bits/stdc++.h>
#define MOD 998244353
#define MAX 100005
using namespace std;
int v[MAX+1];
long long rsq[MAX+1];
int mp[MAX+1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	int x,m;
	cin>>n>>x>>m;
	if(n==1)
	{
		cout<<x<<endl;
		return 0;
	}
	v[1] = x;
	mp[x] = 1;
	long long sum = v[1];
	int a=0,b=0;
	for(int i=2;;++i)
	{
		int y = (v[i-1]*1LL*v[i-1])%m;
		sum += y*1LL;
		if(i==n)
		{
			cout<<sum<<endl;
			return 0;
		}
		if(mp[y]==0)
			v[i] = y,mp[y] = i;
		else
		{
			a = mp[y];
			b = i-1;
			break;
		}
	}	
	long long ans = 0;
	for(int i=1;i<a;++i)
		ans += 1LL*v[i],--n;
	int total = b-a+1;
	for(int i=a,j=1;i<=b;++i,++j)
		rsq[j] = rsq[j-1]+1LL*v[i];
	ans += (n/total)*rsq[total];
	n %= total;
	ans += rsq[n];
	cout<<ans<<endl;
	return 0;
}