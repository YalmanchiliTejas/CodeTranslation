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
	vector< vector<int> > num( N, vector<int>(26,0) );
	for(int i=0;i<N;++i){
		string str;
		cin >> str;
		int size = str.size();
		for(int j=0;j<size;++j){
			int res = str[j]-'a';
			num[i][res]++;
		}
	}
	vector<int> ans(26,INF);
	for(int a=0;a<26;++a){
		for(int i=0;i<N;++i){
			ans[a] = min( ans[a], num[i][a] );
		}
	}
	for(int a=0;a<26;++a){
		int res = ans[a];
		for(int i=0;i<res;++i){
			char temp = 'a'+a;
			cout << temp;
		}
	}
	cout << endl;
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
