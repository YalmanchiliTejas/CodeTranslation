#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=200005;
const ll mod=998244353;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
ll n,a[N],s[N];
int x,m,vis[N];
void solve()
{
	cin >> n >> x >> m;
	if(n == 1) { cout << x << endl; return; }
	a[1] = s[1] = x; vis[x] = 1;
	int k = 0, len = 0;
	for(int i=2; i<=m+2; i++) {
		int y = (a[i-1] * a[i-1]) % m;
		a[i] = y;
		s[i] = s[i-1] + y;
		if(i == n) { cout << s[i] << endl; return; }
		if(vis[y]) { k = vis[y] - 1; len = i - vis[y]; break; }
		vis[y] = i;
	}
	ll ans = s[k];
	ans += (n - k) / len * (s[k+len] - s[k]);
	ans += s[k + (n - k) % len] - s[k];
	cout << ans << endl;
}
int main()
{
	int T=1;
	while(T--) solve();
}