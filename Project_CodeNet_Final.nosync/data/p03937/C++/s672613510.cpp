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
	int H,W;
	cin >> H >> W;
	vector< vector<bool> > fld(H,vector<bool>(W));
	for(int h=0;h<H;++h){
		string str;
		cin >> str;
		for(int w=0;w<W;++w){
			if( str[w] =='#' ){
				fld[h][w] = true;
			}
		}
	}
	if( fld[0][0] == false ){
		cout << "Impossible" << endl;return;
	}
	for(int h=0;h<H;++h){
		for(int w=0;w<W;++w){
			if( fld[h][w] ){
				int res = 0;
				if( h+1<H ){res += fld[h+1][w];}
				if( w+1<W ){res += fld[h][w+1];}
				if( res != 1 ){
					if( h==H-1 && w==W-1 ) continue;//右下は停止
					cout << "Impossible" << endl;
					return;
				}

				int rev = 0;//逆方向もみる
				if( h>0 ){rev += fld[h-1][w];}
				if( w>0 ){rev += fld[h][w-1];}
				if( rev != 1 ){
					if( h==0 && w==0 ) continue;//左上は開始位置
					cout << "Impossible" << endl;
					return;
				}
			}
		}
	}
	cout << "Possible" << endl;
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
