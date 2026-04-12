#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
#define For(i,a,b)  for(int i=a;i<=b;i++)
#define Forr(i,a,b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define int ll
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define mkp make_pair
#define INF (ll)(1e17)
#define MOD (ll)(998244353)

int app[100010];
int sum[100010];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	memset(app,-1,sizeof(app));
	memset(sum,0,sizeof(sum));
	int n,x,m; cin>>n>>x>>m;
	int now=x;
	app[now]=1;
	sum[1]=x;
	int end=-1;
	int len=-1;
	For(i,2,m+5){
		now=(now*now)%m;
		if(app[now]!=-1){
			end=i;
			len=i-app[now];
			break;
		}
		sum[i]=now+sum[i-1];
		app[now]=i;
	}
	if(n<=len){
		cout<<sum[n]<<"\n";
		return 0;
	}
	int k=(n-end+1)/len+1;
	int s=sum[end-1]-sum[end-len-1];
	int left=(n-end+1)%len;
	int ans=(k*s+sum[left+end-len-1]);
	cout<<ans<<"\n";
	return 0;
}





















