#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)>>1)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1<<(x))
#define inf 1000000005
#define MOD 1000000007
#define N 200005
#define M 27000
#define LOG 1000000
#define KOK 650
#define EPS 0.000000001
using namespace std;

int n,m,l,r,x;
ll ans;
ll S[N<<2],lazy[N<<2],dp[N];
vector<ii> v[N];

void push(int node) {

	S[node<<1]+=lazy[node];
	S[node<<1|1]+=lazy[node];	

	lazy[node<<1]+=lazy[node];
	lazy[node<<1|1]+=lazy[node];

	lazy[node]=0;
}

ll get(int node,int bas,int son,int x,int y) {

	if(bas>=x && son<=y) return S[node];

	push(node);

	bool l=(orta>=x);
	bool r=(orta+1<=y);

	if(l&r) return max(get(node<<1,bas,orta,x,y),get(node<<1|1,orta+1,son,x,y));

	if(l) return get(node<<1,bas,orta,x,y);

	return get(node<<1|1,orta+1,son,x,y);

}

void up(int node,int bas,int son,int x,int y,ll val) {

	if(bas>y || son<x) return ;

	if(bas>=x && son<=y) {

		S[node]+=val;

		lazy[node]+=val;

		return ;

	}

	push(node);

	up(node<<1,bas,orta,x,y,val);
	up(node<<1|1,orta+1,son,x,y,val);

	S[node]=max(S[node<<1],S[node<<1|1]);

}

int main() {

	//freopen("input.txt","r",stdin);	

	scanf("%d %d",&n,&m);

	for(int i=1;i<=m;i++) {

		scanf("%d %d %d",&l,&r,&x);

		ans+=x;

		v[r].pb({l,-x});

	}

	for(int i=1;i<=n;i++) {

		int bef=i-2;

		umax(bef,0);

		up(1,1,n,i,i,dp[bef]);

		dp[i]=dp[i-1];

		for(auto x:v[i]) {

			up(1,1,n,1,x.st,x.nd);

		}

		umax(dp[i],get(1,1,n,1,i));

	}

	printf("%lld",dp[n]+ans);

}
