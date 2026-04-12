#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

class Union_Find_Tree{
	public:
	vi Par,Rank;
	Union_Find_Tree(int n){
		Par=Rank=vi(n);
		for(int i=0;i<n;i++) Par[i]=i;
	}
	int Find_Par(int x){
		if(Par[x]==x) return x;
		return Par[x]=Find_Par(Par[x]);
	}
	bool Unite(int x,int y){
		x=Find_Par(x);
		y=Find_Par(y);
		if(x==y) return 0;
		if(Rank[x]<Rank[y]) Par[x]=y;
		else{
			Par[y]=x;
			if(Rank[x]==Rank[y]) Rank[x]++;
		}
		return 1;
	}
	bool Same(int x,int y){
		return Find_Par(x)==Find_Par(y);
	}
};

int n;
vp x,y;

int main(){
	cin>>n;
	x=y=vp(n);
	for(int i=0;i<n;i++){
		cin>>x[i].first>>y[i].first;
		x[i].second=i;
		y[i].second=i;
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	vip a;
	for(int i=1;i<n;i++) a.push_back({abs(x[i].first-x[i-1].first),{x[i].second,x[i-1].second}});
	for(int i=1;i<n;i++) a.push_back({abs(y[i].first-y[i-1].first),{y[i].second,y[i-1].second}});
	sort(a.begin(),a.end());
	Union_Find_Tree uft(n);
	ll res=0;
	for(int i=0;i<2*n-2;i++){
		ll c=a[i].first;
		P p=a[i].second;
		int v=p.first,u=p.second;
		if(!uft.Same(v,u)){
			uft.Unite(v,u);
			res+=c;
		}
	}
	cout<<res<<endl;
}