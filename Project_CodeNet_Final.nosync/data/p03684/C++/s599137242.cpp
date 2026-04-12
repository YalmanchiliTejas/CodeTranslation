#include<bits/stdc++.h>

using namespace std;
#define FILE "dealing"
#define up(i,j,n) for(ll i=j;i<=n;i++)
#define ll long long
#define db double 
#define ull unsigned ll
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define pb push_back

ll read(){
	ll f=1,x=0,ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f*x;
}

const ll maxn=100010,limit=100000,inf=100000000,mod=1e9+7;
ll add(ll a,ll b){return (a+=b)>=mod?a-mod:a;}
ll sub(ll a,ll b){return (a-=b)<  0?a+mod:a;}
ll mul(ll a,ll b){return 1LL*a*b%mod;}
pii a[maxn],b[maxn],t[maxn];
ll n,xid[maxn],yid[maxn],id[maxn];
bool cmp(const pii& a,const pii& b){return a.se<b.se;}
bool vis[maxn];
ll ans=0,d[maxn];
priority_queue<pii ,vector< pii > ,greater< pii > > q;

void updata(ll x,ll dis){
	if(x<1||x>n)return;
	if(d[x]>dis&&!vis[x]){
		d[x]=dis;
		q.push(mp(dis,x));
	}
}
void solve(){
	q.push(mp(0,1));
	memset(d,10,sizeof(d));d[1]=0;
	while(!q.empty()){
		ll x=q.top().se;
		if(vis[x]){q.pop();continue;}
		ans+=q.top().fi;q.pop();
		vis[x]=1;
		updata(x-1,a[x].fi-a[x-1].fi);
		updata(x+1,a[x+1].fi-a[x].fi);
		updata(id[yid[x]-1],a[x].se-a[id[yid[x]-1]].se);
		updata(id[yid[x]+1],a[id[yid[x]+1]].se-a[x].se);
	}
	cout<<ans;
}

int main(){
	//freopen(FILE".in","r",stdin);
	//freopen(FILE".out","w",stdout);
	n=read();
	up(i,1,n)a[i].fi=read(),a[i].se=read();
	sort(a+1,a+n+1);
	up(i,1,n)b[i].fi=a[i].se,b[i].se=i;
	sort(b+1,b+n+1);
	up(i,1,n)yid[b[i].se]=i,xid[i]=i;
	up(i,1,n)id[yid[i]]=i;
	solve();
	return 0;
}




