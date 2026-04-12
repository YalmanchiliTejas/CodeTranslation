#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif
#define LDcout(x,n) fixed<<setprecision(n)<<x

#define MOD 1000000007LL
#define EPS 1e-8
static const int INF=1<<24;
int a[5][5];
int b[6][6];
int ans;
int c[]={0,60,70,80};
int d[5][5];
int e[10000];
int fo1[5][4];
int fo2[5][4];
vector<pii> v;
int bar(int x){
	return c[e[x]];
}
int calc(){
	int ret=0;
	reep(i,1,4){
		ret+=d[2][i]*bar(a[2][i]+b[1][i-1]+b[1][i]+b[2][i-1]+b[2][i]);
		// cout<<i<<" "<<a[2][i]<<" "<<d[2][i]*bar(a[2][i]+b[1][i-1]+b[1][i]+b[2][i-1]+b[2][i])<<endl;
	}
	// cout<<ret<<endl;
	ret+=d[2][0]*bar(a[2][0]+b[1][0]+b[2][0]);
	ret+=d[2][4]*bar(a[2][4]+b[1][3]+b[2][3]);
	// cout<<ret<<endl;
	return ret;
}
int foo1(int x){
	if(x==4){
		return d[0][4]*bar(a[0][4]+b[0][3])    +d[1][4]*bar(a[1][4]+b[0][3]+b[1][3]);
	}
	if(x&&fo1[x][b[0][x-1]]>=0) return fo1[x][b[0][x-1]];
	int ret=0;
	rep(i,4){
		b[v[x].F][v[x].S]=i;
		int t;
		if(x) t=foo1(x+1)+d[0][x]*bar(a[0][x]+b[0][x]+b[0][x-1])+d[1][x]*bar(a[1][x]+b[1][x]+b[1][x-1]+b[0][x]+b[0][x-1]);
		else t=foo1(x+1)+d[0][x]*bar(a[0][x]+b[0][x])           +d[1][x]*bar(a[1][x]+b[0][x]+b[1][x]);
		ret=max(ret,t);
	}
	return fo1[x][b[0][x-1]]=ret;
}
int foo3(int x){
	if(x==16){
		return d[4][4]*bar(a[4][4]+b[3][3])  +d[3][4]*bar(a[3][4]+b[3][3]+b[2][3]);
	}
	if(x!=12&&fo2[x-12][b[3][x-1-12]]>=0) return fo2[x-12][b[3][x-1-12]];
	int ret=0;
	rep(i,4){
		b[v[x].F][v[x].S]=i;
		int t;
		int y=x-12;
		if(x!=12) t=foo3(x+1)+d[4][y]*bar(a[4][y]+b[3][y]+b[3][y-1])+d[3][y]*bar(a[3][y]+b[3][y]+b[3][y-1]+b[2][y]+b[2][y-1]);
		else      t=foo3(x+1)+d[4][y]*bar(a[4][y]+b[3][y])           +d[3][y]*bar(a[3][y]+b[3][y]+b[2][y]);
		ret=max(ret,t);
	}
	return fo2[x-12][b[3][x-1-12]]=ret;
}
int foo2(int x){
	int ret=0;
	if(x==12){
		rep(i,5) rep(j,4) fo1[i][j]=fo2[i][j]=-1;
		int aa=foo1(0);
		int bb=foo3(12);
		// cout<<aa<<" "<<bb<<endl;
		int tmp=calc()+aa+bb;
		return tmp;
	}
	rep(i,4){
		b[v[x].F][v[x].S]=i;
		ret=max(ret,foo2(x+1));
	}
	return ret;
}

void mainmain(){
	int n;
	cin>>n;
	rep(i,10000) e[i]=i%4;
	rep(i,4){
		rep(j,4){
			v.PB(pii(i,j));
		}
	}
	rep(o,n){
		rep(i,5) rep(j,5) cin>>a[i][j],a[i][j]--;
		rep(i,5) rep(j,5){
			if(a[i][j]==-1) a[i][j]=4,d[i][j]=0;
			else d[i][j]=1;
		}
		// cout<<calc2()<<endl;
		ans=foo2(4);
		cout<<ans<<endl;
	}
	// b[2][0]=3;
	// cout<<calc()<<endl;
}


signed main() {
	ios_base::sync_with_stdio(false);
  	cout<<fixed<<setprecision(0);
    mainmain();
}