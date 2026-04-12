#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

int n;

i64 x[202020][2];

int main(){
	cin >> n;
	rep(i,1,n) cin >> x[i][0] >> x[i][1];
	rep(i,1,n) if(x[i][0] < x[i][1]) swap(x[i][0] , x[i][1]);
	x[0][0] = 0;
	x[0][1] = 1e9;
	int MAX = 0;
	int MIN = 0;
	rep(i,1,n){
		if(x[MAX][0] < x[i][0]) MAX = i;
		if(x[MIN][1] > x[i][1]) MIN = i;
	}
	i64 result = 1e18;
	//patten 1. Rmax = MAX , Rmin = MIN
	if(MAX != MIN){
		i64 RMAX = x[MAX][0];
		i64 BMIN = x[MIN][1];
		i64 RMIN = 1e9;
		i64 BMAX = 0;
		rep(i,1,n){
				RMIN = min(RMIN,x[i][0]);
				BMAX = max(BMAX,x[i][1]);
		}
		result = (RMAX - RMIN) * (BMAX - BMIN);
	}

	//patten2 . Rmax = MAX,Rmin = MIN
	{
		i64 RDIF = x[MAX][0] - x[MIN][1];
		set<P> st;
		rep(i,1,n) st.insert({x[i][0],i});
		while(true){
			i64 BDIF = (st.rbegin()->first) - (st.begin()->first);
			result = min(result , RDIF * BDIF);

			P p = *st.rbegin();
			st.erase(*st.rbegin());
			if(p.second == -1) break;
			st.insert({x[p.second][1] , -1});
		}
	}

	cout << result << endl;
}
