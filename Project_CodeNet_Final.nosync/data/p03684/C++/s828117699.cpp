#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int par[200005],ran[200005];
void init(){ for(int i=0;i<200005;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
vector<P1>a,b;
int n;
vector<pair<int,P> >V;
int main(){
	init();
	cin >> n;
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y);
		a.pb(mp(mp(x,y),i));
		b.pb(mp(mp(y,x),i));
	}
	SORT(a);
	SORT(b);
	for(int i=1;i<a.size();i++){
		if(a[i-1].fi.fi == a[i].fi.fi){
			unite(a[i-1].sc,a[i].sc);
		}
		else{
			V.pb(mp(a[i].fi.fi-a[i-1].fi.fi,mp(a[i-1].sc,a[i].sc)));
		}
	}
	for(int i=1;i<b.size();i++){
		if(b[i-1].fi.fi == b[i].fi.fi){
			unite(b[i-1].sc,b[i].sc);
		}
		else{
			V.pb(mp(b[i].fi.fi-b[i-1].fi.fi,mp(b[i-1].sc,b[i].sc)));
		}
	}
	ll ret = 0;
	sort(V.begin(),V.end());
	for(int i=0;i<V.size();i++){
		if(!same(V[i].sc.fi,V[i].sc.sc)){
			unite(V[i].sc.fi,V[i].sc.sc);
			ret += V[i].fi;
		}
	}
	cout << ret << endl;
}