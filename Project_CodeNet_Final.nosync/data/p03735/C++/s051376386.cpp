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
typedef pair<lint,lint> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<pint> v;
int main()
{
	int n;
	lint x,y,rmax=0,rmin=1145141919,bmax=0,bmin=1145141919;
	cin>>n;
	rep(i,n){
		cin>>x>>y;
		if(x>y) swap(x,y);
		v.pb(mp(x,y));
		rmin=min(rmin,x);rmax=max(rmax,y);
		bmin=min(bmin,y);bmax=max(bmax,x);
	}
	if(n<2){
		cout<<0<<endl;return 0;
	}
	sort(All(v));
	lint out=(bmax-rmin)*(rmax-bmin),ma=v[n-1].fi,mi=1145141919;
	rep(i,n-1){
		ma=max(ma,v[i].se);
		mi=min(mi,v[i].se);
		out=min(out,(rmax-rmin)*(ma-min(v[i+1].fi,mi)));
	}
	cout<<out<<endl;
}
