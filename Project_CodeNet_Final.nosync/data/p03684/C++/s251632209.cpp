#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
using namespace std;
#define mp make_pair
#define pb push_back
#define re return
#define fi first
#define se second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<pii> vpii; 
typedef vector<string> vs;
typedef vector<vi> vvi;
int px[100010],py[100010],par[100010];
pii sx[100010],sy[100010];
int find(int x){
	return x==par[x] ? x : par[x]=find(par[x]);
}
int unite(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v)return 0;
	par[u]=v;
	return 1;
}
int dist(int x,int y){
	return min(abs(px[x]-px[y]),abs(py[x]-py[y]));
}
int main() {
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>px[i]>>py[i];
		par[i]=i;
		sx[i]=mp(px[i],i);
		sy[i]=mp(py[i],i);
	}
	sort(sx,sx+n);
	sort(sy,sy+n);
	set<pair<int,pii> > st;
	for(int i=0;i<n-1;i++){
		st.insert(mp(dist(sx[i].second,sx[i+1].second),mp(sx[i].second,sx[i+1].second)));
		st.insert(mp(dist(sy[i].second,sy[i+1].second),mp(sy[i].second,sy[i+1].second)));
	}
	long long ans=0;
	while(st.size()){
		pair<int,pii> cur=*st.begin();
		st.erase(cur);
		int u=cur.second.first,v=cur.second.second;
		ans+=unite(u,v)*dist(u,v);
	}
	cout<<ans<<endl;
    return 0;
}