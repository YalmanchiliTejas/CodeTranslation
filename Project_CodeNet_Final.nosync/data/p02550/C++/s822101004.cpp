#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;

ll n;
int x, p;
int a[maxn], vis[maxn];
ll b[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	scanf("%lld%d%d", &n, &x, &p);
	a[1] = x, vis[x] = 1;
	int l, r, cnt = 1;
	while(1){
		a[cnt+1] = 1ll * a[cnt] * a[cnt] % p;
		++cnt;
		if(vis[a[cnt]]){
			l = vis[a[cnt]], r = cnt - vis[a[cnt]];
			break;
		}
		vis[a[cnt]] = cnt;
	}
	for(int i = 1; i <= cnt; ++i) b[i] = b[i-1] + 1ll * a[i];
	
	cout << (b[cnt-1] - b[l-1]) * ((n - l + 1) / r) + b[(n-l+1)%r+l-1];
}