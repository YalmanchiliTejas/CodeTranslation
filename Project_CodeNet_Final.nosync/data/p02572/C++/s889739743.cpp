#include<bits/stdc++.h>
#define MOD 1000000007
#define MAX 200000
using namespace std;
int rsq[MAX+1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int v[n+1];
	long long ans = 0;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
		ans += (v[i]*1LL*rsq[i-1])%MOD;
		ans %= MOD;
		rsq[i] = (rsq[i-1]*1LL+v[i]*1LL)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}