#include <bits/stdc++.h>
//#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;

struct edge {
	int to, cost;
	edge(int t,int c):to(t),cost(c) {}
};
int ddx[]={1,1,1,0,-1,-1,-1,0},ddy[]={1,0,-1,-1,-1,0,1,1};


//-----------------------------------------------------------------------------

int x,y,z;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>x>>y>>z;
	if(x<y+z+z) cout<<0<<endl;
	else {
		x-=y+z+z;
		cout<<1+(x/(y+z))<<endl;
	}

	return 0;
}
