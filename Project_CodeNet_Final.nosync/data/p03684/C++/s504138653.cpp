#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
#define endl '\n'
#define inf 0x3f3f3f3f
#define lb lower_bound
#define db(x) {cout <<"#db " << x << endl;}
#define here() {cout <<"here \n";}
#define mod 1000000007
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int par[N];
int n,te,ans = 0,use = 0;
int find(int x){
	if(x == par[x])return x;
	return par[x] = find(par[x]);
}
struct point{
	int id,X,Y;
}p[N];
bool cmpx(point a,point b){
	return a.X <b.X;
}
bool cmpy(point a,point b){
	return a.Y <b.Y;
}
struct edge{
	int u,v;
	int w;
}e[N<<1];
bool cmpe(edge a,edge b){
	return a.w < b.w;
}
signed main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		par[i] = i;
		int x,y; cin >> x >> y;
		p[i].id = i;
		p[i].X = x;p[i].Y = y;
	}
	sort(p,p+n,cmpx);
	for(int i = 1 ; i < n ; i ++ ){
		e[te].w = p[i].X - p[i-1].X;
		e[te].u = p[i].id;
		e[te].v = p[i-1].id;
		te ++;
	}
	sort(p,p+n,cmpy);
	for(int i = 1 ; i < n ; i ++ ){
		e[te].w = p[i].Y - p[i-1].Y;
		e[te].u = p[i].id;
		e[te].v = p[i-1].id;
		te ++;
	}
	sort(e,e+te,cmpe);
	for(int i = 0 ; i < te ; i ++){
		int st = find(e[i].u);
		int en = find(e[i].v);
		if(st != en){
			ans += e[i].w;
			par[st] = en;
			use ++;
		}
		if(use == n - 1){
			cout << ans;
			return 0;
		}
	}
	return 0;
}
