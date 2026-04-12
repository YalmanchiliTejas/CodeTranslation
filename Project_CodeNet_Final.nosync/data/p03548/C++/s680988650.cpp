#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int,P> PP;

struct edge {
	int to,cost;
	edge(int t,ll c):to(t),cost(c) {}
};

int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int ddx[]={1,1,1,0,-1,-1,-1,0},ddy[]={1,0,-1,-1,-1,0,1,1};

//-----------------------------------------------------------------------------

int x,y,z;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>x>>y>>z;
	x-=z;
	int ans=x/(y+z);
	cout<<ans<<endl;

	return 0;
}
