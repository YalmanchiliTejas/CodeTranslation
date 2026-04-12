#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
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
#define inf 2005000000
#define MOD 1000000007
#define N 100005
#define M 100000000
#define LOG 22
#define KOK 4000000
using namespace std;

int n,a,b;
int dp[N];
vector<int> v[N];

void dfs(int node,int ata) {

	int deg=0;

	for(int i:v[node]) {

		if(i==ata) continue ;

		dfs(i,node);

		deg+=dp[i];

	}

	if(deg<=1) {

		dp[node]=!deg;

	}
	else {

		printf("First");

		exit(0);

	}

}

int main() {

	//freopen("input.txt","r",stdin);

	scanf("%d",&n);

	for(int i=1;i<n;i++) {

		scanf("%d %d",&a,&b);

		v[a].pb(b);
		v[b].pb(a);

	}

	if(n==2) {

		printf("Second");

		return 0;

	}

	int root=1;

	for(int i=1;i<=n;i++) if(sz(v[i])>1) root=i;

	dfs(root,0);

	printf("Second");

}