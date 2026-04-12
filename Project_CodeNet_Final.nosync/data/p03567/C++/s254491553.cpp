#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
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
#define ALL(X) X.begin(), X.end()
/////////
#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef std::pair<LL,LL> PLL;//
typedef std::pair<int,int> PII;//
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const LL MOD = (LL)1e9+7;
const LL LINF = (LL)4e18+20;
const LD PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;

void solve(){
	string str;
	cin >> str;
	int size = str.size();
	for(int i=0;i<size-1;++i){
		if( str[i] == 'A' && str[i+1] == 'C' ){
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
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