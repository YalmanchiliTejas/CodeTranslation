/*input
1
1 5
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <cmath>
#include <cstring>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <list>
#include <cstdlib>
#include <list>
#include <cassert>
#include <ctime>
#include <fstream>
#include <sstream>
#define fi first
#define se second
#define endl '\n'
#define N 100005
#define INF 1000000000
#define mod 1000000007
#define oo 1000000000000000000
// #define int long long
using namespace std;
typedef pair<int,int> ii;
long long n,res = 0,u,v;
vector<ii> a,b;
// map<ii,bool> done;
vector<pair<int,ii> > adj;
vector<int> pset;
void init(int n){
	pset.assign(n+1,0);
	for(int i=1;i<=n;i++){
		pset[i] = i;
	}
}
int findset(int i){
	if(pset[i] == i) return i;
	return pset[i] = findset(pset[i]);
}
bool issameset(int i,int j){
	return findset(i) == findset(j);
}
void unionset(int i,int j){
	if(issameset(i,j)) return;
	pset[findset(j)] = findset(i);
}
signed main(){
	ios_base::sync_with_stdio(0);
	// freopen(".inp","r",stdin);
	// freopen(".out","w",stdout);
	cin >> n;
	init(n);
	for(int i=1;i<=n;i++){
		cin >> u >> v;
		a.push_back(ii(u,i));
		b.push_back(ii(v,i));
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i=1;i<n;i++){
		adj.push_back(make_pair(a[i].fi - a[i-1].fi,ii(a[i].se,a[i-1].se)));
		adj.push_back(make_pair(b[i].fi - b[i-1].fi,ii(b[i].se,b[i-1].se)));
	}
	sort(adj.begin(),adj.end());
	for(int i=0;i<adj.size();i++){
		u = adj[i].se.fi, v = adj[i].se.se;
		if(issameset(u,v)) continue;
		unionset(u,v);
		res += adj[i].fi;
	}
	cout << res << endl;
    return 0;
}