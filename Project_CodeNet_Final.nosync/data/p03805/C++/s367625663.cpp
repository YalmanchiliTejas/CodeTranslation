#ifdef __GNUC__
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#endif

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <cmath>

#include <string>
#include <cstring>
#include <vector>
#include <valarray>
//#include <array>//x C++ (G++ 4.6.4)

#include <queue>
#include <complex>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <cassert>//assert();
#include <fstream>
/////////
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)

/////////
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#define PII pair<int,int>
/////////
using namespace::std;

// 最大公約数
template<class T>
inline T gcd(T a, T b){return b == 0 ? a : gcd(b, a % b);}
// 最小公倍数
template<class T>
inline T lcm(T a, T b){return a * b / gcd(a, b);}
////////////////////////////////
vector< vector<bool> > G;
vector<bool> used;
int N;

int dfs(int pos){
	int RET = 0;//返す値。
	int TEMP = 0;
	int res;
	bool flag = true;
	for(int i=0;i<N;++i){
		if( used[i] == false ){
			flag = false;
			break;
		}
	}
	if( flag == true ){
		return 1;
	}
	for(int i=0;i<N;++i){
		if( used[i] ) continue;
		if( pos == i ) continue;
		if( G[pos][i] == false)continue;
		used[i] = true;
		res = dfs(i);
		if( res != -1 ){
			RET += res;
		}
		used[i] = false;
	}
	return RET;
}

inline void solve(){
	int M;
	cin >> N >> M;
	G = vector< vector<bool> >(N,vector<bool>(N,false) );
	used = vector<bool>(N,false);
	int a,b;
	for(int i=0;i<M;++i){
		cin >> a >> b;
		--a;--b;
		G[a][b] = true;
		G[b][a] = true;
	}
	
	used[0] = true;
	int ret = dfs(0);
	cout << ret << endl;
}

signed main(void){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	//std::cout << std::fixed;//小数を10進数表示
	//cout << setprecision(16);//小数をいっぱい表示する。16?

	solve();
}
