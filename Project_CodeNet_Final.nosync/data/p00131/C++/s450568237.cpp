#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
//#include <utility>
#include <set>
#include <iostream>
//#include <memory>
#include <string>
#include <vector>
#include <algorithm>
//#include <functional>
#include <sstream>
//#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
//#include <cctype>
#include <cstring>
//#include <ctime>
#include <iterator>
#include <bitset>
//#include <numeric>
//#include <list>
//#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#else

#endif

using namespace std;


namespace{
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


#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8
static const int INF=1<<24;
vvint vv,tt,ans;
int dd[]={0,1,0,-1,0};
bool check(int y,int x){
	if(0<=y&&y<10&&0<=x&&x<10) return true;
	return false;
}
void foo(int y,int x){
	tt[y][x]=1-tt[y][x];
	rep(i,4){
		if(check(y+dd[i],x+dd[i+1])) tt[y+dd[i]][x+dd[i+1]]=1-tt[y+dd[i]][x+dd[i+1]];
	}
}
void mainmain(){
	int n;
	cin>>n;
	rep(g,n){
		// vvint vv;
		initvv(vv,10,10);
		rep(i,10) rep(j,10) cin>>vv[i][j];
		rep(i,1<<10){
			tt=vv;
			initvv(ans,10,10,0);
			rep(j,10){
				if(i&(1<<j)){
					ans[0][j]=1;
					foo(0,j);
				}
			}
			reep(j,1,10){
				rep(k,10){
					if(tt[j-1][k]==1){
						ans[j][k]=1;
						foo(j,k);
					}
				}
			}
			bool f=true;
			rep(j,10){
				if(tt[9][j]==1){
					f=false;
					break;
				}
			}
			if(f){
				rep(j,10){
					rep(k,10){
						if(k) cout<<" ";
						cout<<ans[j][k];
					}
					cout<<endl;
				}
				break;
			}
		}
	}
}



}
main() try{
    mainmain();
}
catch(...){
}