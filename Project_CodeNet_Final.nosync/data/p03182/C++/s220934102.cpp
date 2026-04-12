#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
#include <fstream>
#include <queue>
#include <iomanip>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#include <assert.h>
#include <numeric>
#define fast ios_base::sync_with_stdio(false)
#define mxn (ll)2e5
#define mod (ll)(1e9+7)
#define mod1 (ll)(998244353)
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vvi vector<vi >
#define pi pair<ll,ll>
#define vvpi vector<vector<pi > >
#define vpi vector<pi >
#define vppi vector<pair<ll,pi > >
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define fs first
#define se second
#define crz(v,n) v.clear(),v.resize(n+1,0)
#define print(v) for(ll it=0;it<v.size();it++) cout<<v[it]<<" ";cout<<endl
#define printp(v) for(ll it=0;it<v.size();it++) cout<<v[it].first<<" "<<v[it].second<<endl
using namespace std;
int n;vi tree(5*mxn),lz(5*mxn);
struct stree{
	void push(int x,int s,int e){
		if(lz[x]){
			tree[x]+=lz[x];
			if(s-e){
				for(int i:{2*x,2*x+1}) lz[i]+=lz[x];
			}lz[x]=0;
		}
	}
	void add(int us,int ue,ll val,int s=0,int e=n,int x=1){
		push(x,s,e);
		if(s>ue||e<us) return;
		if(s>=us&&e<=ue){
			lz[x]+=val;
			push(x,s,e);
		}else{
			add(us,ue,val,s,(s+e)/2,x*2);
			add(us,ue,val,(s+e)/2+1,e,x*2+1);
			tree[x]=max(tree[x*2],tree[x*2+1]);
		}
	}ll query(int qs,int qe,int s=0,int e=n,int x=1){
		push(x,s,e);
		if(s>qe||e<qs) return -1e18;
		if(s>=qs&&e<=qe) return tree[x];
		else return max(query(qs,qe,s,(s+e)/2,x*2),query(qs,qe,(s+e)/2+1,e,x*2+1));
	}
};
int main(){
	int m,i;cin>>n>>m;vi d(n+1,0);
	vvi st(n+1);vvpi en(n+1);
	for(i=0;i<m;i++){
		int l,r,a;cin>>l>>r>>a;
		st[l].pb(a);
		en[r].eb(l,a);
	}stree t;
	for(i=1;i<=n;i++){
		for(auto j:st[i]) t.add(0,i-1,j);
		//~ t.prin();
		d[i]=t.query(0,i-1);
		t.add(i,i,d[i]);
		for(pi j:en[i]) t.add(0,j.fs-1,-j.se);
	}
	cout<<*max_element(all(d))<<endl;
}
