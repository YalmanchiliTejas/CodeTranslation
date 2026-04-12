//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);  
int dsu[123456];
struct total{
	int val,u,v;
}; 
int compar(total a,total b){
	return a.val<b.val;
}
vector<total> edges;
vii vec1,vec2;
int x[123456],y[123456];
int calc(int a,int b){
	return min(abs(x[a]-x[b]),abs(y[a]-y[b]));
}
int find(int u){
	if(dsu[u]<0)return u;
	dsu[u]=find(dsu[u]);
	return dsu[u];
}
int merge(int u,int v){
	u=find(u);
	v=find(v);
	if(u!=v){
		if(dsu[u]>dsu[v]){
			dsu[u]=v;
		}
		else{
			dsu[v]=u;
		}
	}
	else{
		dsu[u]=v;
		dsu[v]--;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int i;
	total haha;
	//return 0;
	rep(i,n){

		dsu[i]=-1;
		cin>>x[i]>>y[i];
		vec1.pb(mp(x[i],i));
		vec2.pb(mp(y[i],i));
	}
	//return 0;
	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
	//return 0;
	f(i,1,n){
		
		haha.u=vec1[i].ss;
		haha.v=vec1[i-1].ss;
		haha.val=calc(haha.u,haha.v);
		edges.pb(haha);
		
		haha.u=vec2[i].ss;
		haha.v=vec2[i-1].ss;
		haha.val=calc(haha.u,haha.v);
		edges.pb(haha);
	}
	sort(edges.begin(),edges.end(),compar);
	ll ans=0;
    rep(i,edges.size()){
    	//cout<<edges[i].val<<" "<<find(edges[i].u)<<" "<<find(edges[i].v)<<endl;
    	if(find(edges[i].u)!=find(edges[i].v)){
    		ans+=edges[i].val;
    		merge(edges[i].u,edges[i].v);
    	}
    }
    cout<<ans<<endl;
}

