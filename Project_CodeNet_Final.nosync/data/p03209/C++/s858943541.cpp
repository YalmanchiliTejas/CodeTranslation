#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll p[51],a[51];

void build()
{
	p[0]=1;
	a[0]=1;
	for(int i=1;i<=50;i++)
	{
		p[i]=p[i-1]*2+1;
		a[i]=a[i-1]*2+3;
	}
}

ll eat(ll lvl,ll &rem)
{
	if(rem<=0) return 0;
	if(rem>=a[lvl])
	{
		rem-=a[lvl];
		return p[lvl];
	}
	rem--;
	ll n=eat(lvl-1,rem);
	if(rem==0) return n;
	rem--; n++;
	n+=eat(lvl-1,rem);
	if(rem>0) rem--;
	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	build();
	ll l,r; cin>>l>>r;
	cout<<eat(l,r)<<"\n";
	return 0;
}