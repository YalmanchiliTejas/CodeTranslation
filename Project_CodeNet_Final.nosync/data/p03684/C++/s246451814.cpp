#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
typedef pair<int,pint> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
struct unionf{
	vector <int> data;
	unionf(int size):data(size,-1){}
	bool unions(int x,int y){
		x=root(x);y=root(y);
		if(x!=y){
			if(data[y]<data[x]){int d=x;x=y;y=d;}
			data[x]+=data[y];data[y]=x;
		}
		return x!=y;
	}
	bool finds(int x,int y){
		return root(x)==root(y);
	}
	int root(int x){
		return data[x]<0?x:data[x]=root(data[x]);
	}
	int find(int x){
		return -data[x];
	}
};
vector<tint> ed;
vector<pint> v,w;
int main()
{
	int n,x,y,out=0;
	cin>>n;
	rep(i,n){
		cin>>x>>y;
		v.pb(mp(x,i));w.pb(mp(y,i));
	}
	sort(All(v));sort(All(w));
	rep(i,n-1){
		ed.pb(mp(v[i+1].fi-v[i].fi,mp(v[i].se,v[i+1].se)));
		ed.pb(mp(w[i+1].fi-w[i].fi,mp(w[i].se,w[i+1].se)));
	}
	sort(All(ed));
	unionf uni(n+10);
	rep(i,ed.size()){
		x=ed[i].se.fi;y=ed[i].se.se;
		if(uni.finds(x,y)) continue;
		out+=ed[i].fi;
		uni.unions(x,y);
	}
	cout<<out<<endl;
}
