#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define int ll
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

vector<int> total(51),patty(51);
void init()
{
	total[0]=1;
	For(i,1,50) total[i]=total[i-1]*2+3;
	patty[0]=1;
	For(i,1,50) patty[i]=patty[i-1]*2+1;
}

int eat(int layer,int &lim)
{
	if(lim<=0) return 0;
	if(lim>=total[layer])
	{
		lim-=total[layer];
		return patty[layer];
	}
	int ans=0;
	lim--;
	ans+=eat(layer-1,lim);
	if(lim>0) lim--,ans++;
	ans+=eat(layer-1,lim);
	lim--;
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	int n,k; cin>>n>>k;
	cout<<eat(n,k)<<"\n";
	return 0;
}













