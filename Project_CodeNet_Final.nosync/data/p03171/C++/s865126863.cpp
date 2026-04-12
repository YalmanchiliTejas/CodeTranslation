#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll n; 
ll a[3030];
ll dp[3030][3030];
ll vis[3030][3030];

ll f(ll x, ll y){
	ll &r=dp[x][y];
	if(vis[x][y])return r;
	vis[x][y]=1;
	if(y==x+1){
		r=a[x]; return r;
	}
	r=max(a[y-1]-f(x,y-1),a[x]-f(x+1,y));
	return r;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	cout<<f(0,n);	
	return 0;
}