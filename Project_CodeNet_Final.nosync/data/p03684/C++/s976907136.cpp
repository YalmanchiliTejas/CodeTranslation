#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
const int oo = 1e9 + 7;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int n, par[100001], sz[100001];
vector<iii> point, edg;

int dist(int a, int b, int c, int d){
	return min(abs(a - c), abs(b - d));
}

int anc(int x){
	if(par[x] == -1) return x;
	else return (par[x] = anc(par[x]));
}

bool issameset(int x, int y){ return (anc(x) == anc(y));}

void uni(int x, int y){
	x = anc(x);
	y = anc(y);
	if(sz[x] > sz[y]){
		sz[x] += sz[y];
		par[y] = x;
	}
	else{
		sz[y] += sz[x];
		par[x] = y;
	}
}

bool cmp(iii a, iii b){
	return a.se < b.se;
}

signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		iii pt;
		cin >> pt.fi.fi >> pt.fi.se;
		pt.second = i;
		point.push_back(pt);
	}
	point.push_back(make_pair(make_pair(-oo, -oo), 0));
	point.push_back(make_pair(make_pair(2 * oo, 2 * oo), 0));
	sort(point.begin(), point.end());
	for(int i = 2; i <= n; i++){
	    edg.push_back(make_pair(make_pair(point[i].se, point[i - 1].se), dist(point[i].fi.fi, point[i].fi.se, point[i - 1].fi.fi, point[i - 1].fi.se)));
	}
	for(int i = 1; i <= n; i++) swap(point[i].fi.fi, point[i].fi.se);
	sort(point.begin(), point.end());
	for(int i = 2; i <= n; i++){
	    edg.push_back(make_pair(make_pair(point[i].se, point[i - 1].se), dist(point[i].fi.fi, point[i].fi.se, point[i - 1].fi.fi, point[i - 1].fi.se)));
	}
	//cout << edg[3].fi.fi << " " << edg[3].fi.se << endl;
	for(int i = 1; i <= n; i++) par[i] = -1;
	sort(edg.begin(), edg.end(), cmp);
	int ans = 0;
	for(int i = 0; i < edg.size(); i++){
	    //cout << edg[i].fi.fi << " " << edg[i].fi.se << " " << edg[i].se << " ";
	    if(!issameset(edg[i].fi.fi, edg[i].fi.se)){
	        //cout << 1;
	        ans += edg[i].se;
	        uni(edg[i].fi.fi, edg[i].fi.se);
	    }
	    cout << endl;
	}
	cout << ans;
}