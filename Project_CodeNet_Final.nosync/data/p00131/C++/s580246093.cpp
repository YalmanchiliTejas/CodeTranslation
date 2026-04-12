#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (int)(count); i++)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 100000 ;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

using namespace std;

bool flip[10][10];
bool tmp[10][10];

bool get(int h,int w){
	static int dh[] = {1,0,0,0,-1};
	static int dw[] = {0,1,0,-1,0};
	bool ret = flip[h][w];
	FOR(i,5){
		int nh = dh[i]+h,nw = dw[i]+w;
		if(0 <= nh && nh < 10 && 0 <= nw && nw < 10)
			ret ^= tmp[nh][nw];
	}

	return ret;
}

int main()
{
	int n; cin>>n;
	while(n--){
		FOR(i,10) FOR(j,10){ int x; cin>>x; flip[i][j] = x == 1; }
		FOR(i,2<<10){
			memset(tmp,0,sizeof(tmp));
			FOR(j,10) tmp[0][j] = (i & (1 << j)) != 0;
			for(int j = 1; j < 10; j++) for(int k = 0; k < 10; k++){
				tmp[j][k] = get(j-1,k);
			}
			bool ok = true;
			FOR(j,10) if(get(9,j)){
				ok = false;
				break;
			}
			if(ok) break;
		}
		FOR(i,10) FOR(j,10) printf("%d%c",tmp[i][j],j == 9 ? '\n' : ' ');
	}
	return 0;
}