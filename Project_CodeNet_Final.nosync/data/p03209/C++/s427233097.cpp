#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

ll a[60],b[60];
ll ans=0;

void dfs(int n,ll x){
	if(x<=0)return;
	if(a[n]<=x){
		ans+=b[n];
		return;
	}
	if(a[n-1]+2<=x)ans++;
	dfs(n-1,x-1);
	dfs(n-1,x-a[n-1]-2);
}
signed main(){
	int n;ll x;cin>>n>>x;
	a[0]=1;b[0]=1;
	for(int i=1;i<=n;i++)a[i]=a[i-1]*2+3;
	for(int i=1;i<=n;i++)b[i]=b[i-1]*2+1;
	dfs(n,x);
	cout<<ans<<endl;
}