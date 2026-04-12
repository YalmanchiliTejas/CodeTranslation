#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll n;

struct Rect {
	ll left;
	ll right;
	ll top;
	ll bottom;
};

void dfs(P p, vector<vector<bitset<50>>>& stat, vector<vector<bool>>& used, bitset<50>& tgt) {
	used[p.first][p.second]=true;
	ll dx[]={1,0,-1,0};
	ll dy[]={0,1,0,-1};
	REP(i,4) {
		ll nx=p.first+dx[i];
		ll ny=p.second+dy[i];
		if(nx>=0&&nx<used.size()&&ny>=0&&ny<used[0].size()&&!used[nx][ny]
		   &&stat[nx][ny].to_ullong()==tgt.to_ullong()) dfs(P(nx,ny),stat,used,tgt);
	}
}

ll solve() {
	vector<Rect> rec(n);
	vector<ll> x;
	vector<ll> y;
	REP(i,n) {
		ll l,t,r,b;
		cin>>l>>t>>r>>b;
		x.pb(l); x.pb(r);
		y.pb(t); y.pb(b);
		rec[i]={l,r,t,b};
	}
	x.pb(-1); x.pb(1000001);
	y.pb(-1); y.pb(1000001);
	UNIQUE(x);
	UNIQUE(y);
	REP(i,n) {
		rec[i].left=find(ALL(x),rec[i].left)-x.begin();
		rec[i].right=find(ALL(x),rec[i].right)-x.begin();
		rec[i].top=find(ALL(y),rec[i].top)-y.begin();
		rec[i].bottom=find(ALL(y),rec[i].bottom)-y.begin();
	}
	vector<vector<bitset<50>>> stat(x.size()-1,vector<bitset<50>>(y.size()-1,bitset<50>(0)));
	REP(k,n) {
		FOR(i,rec[k].left,rec[k].right) {
			FOR(j,rec[k].bottom,rec[k].top) stat[i][j][k]=1;
		}
	}
	vector<vector<bool>> used(x.size()-1,vector<bool>(y.size()-1,false));
	ll ret=0;
	REP(i,x.size()-1) REP(j,y.size()-1) {
		if(!used[i][j]) {
			ret++;
			dfs(P(i,j),stat,used,stat[i][j]);
		}
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	while(1) {
		cin>>n;
		if(n==0) break;
		cout<<solve()<<endl;
	}
}

