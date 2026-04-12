#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define lli unsigned long long int
#define MOD 1000000007
#define DEBUG 0
#define REP(i,n) for(int i=0;i<n;i++)

using pii=pair<lli,lli>;

lli pa[100001],n;
vector<pii> xp,yp;

struct edge{
	lli u,v,w;
	edge(){}
	edge(lli u,lli v,lli w):u(u),v(v),w(w){}
	bool operator < (const edge &rhs)const{
		return w < rhs.w;
	}
};

vector<edge> ev;

void add(vector<pii> &arr){
	for(lli i=0;i<arr.size()-1;i++)ev.push_back(edge(arr[i].se,arr[i+1].se,arr[i+1].fi-arr[i].fi));
}

int find(int cur){return cur==pa[cur] ? cur:pa[cur]=find(pa[cur]);}

bool merge(lli u,lli v){
	u = find(u);
	v = find(v);
	if(u==v)return false;

	pa[v] = u;
	return true;
}

int main(){

	cin>>n;
	REP(i,n){
		lli x,y;
		cin>>x>>y;
		xp.push_back(pii(x,i));
		yp.push_back(pii(y,i));
	}
	sort(xp.begin(),xp.end());
	sort(yp.begin(),yp.end());

	add(xp);
	add(yp);

	sort(ev.begin(),ev.end());

	lli ans = 0;
	REP(i,n)pa[i]=i;
	for(auto &e:ev){
		if(merge(e.u,e.v)){
			ans += e.w;
		}
	}

	cout<<ans<<endl;

	return 0;
}
 