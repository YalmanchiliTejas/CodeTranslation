#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <tuple>
#include <bitset>

#include <queue>
#include <complex>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <fstream>
#include <random>
//#include <time.h>
#include <ctime>
#pragma endregion //#include
/////////
#define REP(i, x, n) for(int i = x; i < n; ++i)
#define rep(i,n) REP(i,0,n)
/////////
#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const LL MOD = (LL)1e9+7;
const LL LINF = (LL)1e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;

void solve(){
	int N;
	cin >> N;
	vector< pair<LL,LL> > v(N);
	LL MIN = INF;
	LL MAX = 0;
	for(int i=0;i<N;++i){
		cin >> v[i].first >> v[i].second;
		if( v[i].first > v[i].second ){
			swap( v[i].first, v[i].second );
		}
		MIN = min( MIN, v[i].first );
		MAX = max( MAX, v[i].second );
	}
	sort( v.begin(), v.end() );

	/*
	Rmax = MAX && Bmin = MIN
	*/
	LL ans1 = LINF;
	LL Rmin = LINF;
	LL Bmin = LINF;
	LL Rmax = 0;
	LL Bmax = 0;
	Rmax = MAX;//Rminを大きくする
	Bmin = MIN;//Bmaxを小さくする
	for(int i=0;i<N;++i){
		Rmin = min( Rmin, v[i].second );//大きい方をRへ
		Bmax = max( Bmax, v[i].first );//小さい方をBへ
	}
	ans1 = (Rmax-Rmin) * (Bmax-Bmin);
	
	/*
	Rmax = MAX, Rmin = MIN
	*/
	Rmin = MIN;
	Rmax = MAX;
	Bmin = LINF;
	Bmax = 0;
	LL ans2 = LINF;

	vector< pair<LL,LL> > rui(N);
	for(int i=N-1;i>=0;--i){
		if( i == N-1 ){
			rui[i].first = v[i].first;
			rui[i].second = v[i].first;
		}else{
			rui[i].first = min( rui[i+1].first,v[i].first);
			rui[i].second = max( rui[i+1].second, v[i].first );
		}
	}
	
	LL BminPre = LINF;
	LL BmaxPre = 0;
	for(int i=0;i<=N;++i){//大きい方をBにする個数。
		if( i < N ){
			Bmin = rui[i].first;
			Bmax = rui[i].second;
		}else{
			Bmin = LINF;
			Bmax = 0;
		}
		if( i ){
			BminPre = min( BminPre,v[i-1].second );
			BmaxPre = max( BmaxPre,v[i-1].second );
			Bmin = min( Bmin, BminPre );
			Bmax = max( Bmax, BmaxPre );
		}
		ans2 = min( ans2,(Rmax-Rmin)*(Bmax-Bmin) );
	}
	cout << min(ans1,ans2) << endl;
}

#pragma region main
signed main(void){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	
	
	solve();
}
#pragma endregion //main()
