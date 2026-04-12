////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>
//#include <chrono>
//#include <random>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N = 2e5;
vector<pair<LL,LL> >vec[N + 5];

LL dp[N + 5];
LL ST[4 * N + 5];
LL lazy[4 * N + 5];

void pushdown(int idx,int l,int r) {
	if(lazy[idx] == 0 || l == r) return ;
	ST[2 * idx] += lazy[idx];
	ST[2 * idx + 1] += lazy[idx];
	lazy[2 * idx] += lazy[idx];
	lazy[2 * idx + 1] += lazy[idx];
	lazy[idx] = 0;
}

void update(int idx,int l,int r,int le,int ri,LL v) {
	pushdown(idx,l,r);
	if(r < le || ri < l) return ;
	if(le <= l && r <= ri) {
		ST[idx] += v;
		lazy[idx] += v;
		return ;
	}
	int mid = (l + r) / 2;
	update(2 * idx,l,mid,le,ri,v), update(2 * idx + 1,mid + 1,r,le,ri,v);
	ST[idx] = max(ST[2 * idx], ST[2 * idx + 1]);
}

LL query(int idx,int l,int r,int le,int ri) {
	pushdown(idx,l,r);
	if(r < le || ri < l) return -1e18;
	if(le <= l && r <= ri) return ST[idx];
	int mid = (l + r) / 2;
	return max(query(2 * idx,l,mid,le,ri),query(2 * idx + 1,mid + 1,r,le,ri));
}

void hora(int tc) {
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < m;i++) {
		int l,r,x;
		cin>>l>>r>>x;
		vec[l].PB({l - 1,x});
		vec[r + 1].PB({l - 1,-x});
	}
	LL res = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j < vec[i].size();j++) {
			int x = vec[i][j].FI;
			LL v = vec[i][j].SE;
			update(1,0,n,0,x,v);
		}
		dp[i] = query(1,0,n,0,i - 1);
		update(1,0,n,i,i,dp[i]);
		res = max(res,dp[i]);
	}
	cout<<res<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}

