#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;
typedef vector<map<lli,lli>> graph;

lli n;
vll x,y;
vll xid,yid;

vll par;
vll rnk;
void init(lli n){
    par = vll(n);
    rnk = vll(n);
    for(lli i = 0;i < n;i++) par[i] = i;
}
lli find(lli x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}
void unite(lli x,lli y){
    x = find(x);y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y]) par[x] = y;
    else {
        par[y] = x;
        if(rnk[x] == rnk[y]) rnk[x]++;
    }
}
bool same(lli x,lli y){
    return find(x) == find(y);
}

mat dist;
lli ans = 0;

int main(){
	cin >> n;
	x = vll(n);y = vll(n);
	for(lli i = 0;i < n;i++) cin >> x[i] >> y[i];
	xid = vll(n);yid = vll(n);
	for(lli i = 0;i < n;i++) xid[i] = yid[i] = i;
	sort(xid.begin(), xid.end(),[](lli a,lli b){
		return x[a] < x[b];
	});
	sort(yid.begin(), yid.end(),[](lli a,lli b){
		return y[a] < y[b];
	});
	for(lli i = 0;i < n-1;i++){
		dist.push_back(vll({x[xid[i+1]] - x[xid[i]],xid[i],xid[i+1]}));
		dist.push_back(vll({y[yid[i+1]] - y[yid[i]],yid[i],yid[i+1]}));
	}	
	sort(dist.begin(), dist.end());
	init(n);
	for(lli i = 0;i < dist.size();i++){
		if(!same(dist[i][1],dist[i][2])){
			unite(dist[i][1],dist[i][2]);
			ans += dist[i][0];
		}
	}
	cout << ans << endl;

	return 0;
}