#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int maxM = 2e5+7;
const int maxV = 90010;
 
const int MOD = 1e9+7;
 
int T;
const int maxN = 2e5+8;
const ll INF = 1000000000000000010LL;
const int K = 15;
int n;
int a[maxN];
int t[maxN];
int lowbit(int x)
{
	return x & (-x);
}
void add(int x,int p)
{
	for(;x<=n;x += lowbit(x))
	{
		t[x] = max(t[x],p);
	}
}
int get(int x)
{
	int p = 0;
	for(; x; x-=lowbit(x))
	{
		p = max(p,t[x]);
	}
	return p;
}
int main() {
	scanf("%d",&n);
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)
	{
		int p = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
		a[i] = p; 
	}
	reverse(a+1,a+n+1); 
	int ans = 1;
	for(int i=1;i<=n;i++)
	{
		int x = a[i];
		int v = get(x);
		add(x,v+1);
		ans = max(ans,v+1); 
	}
	cout<<ans<<endl;
    return 0;
}