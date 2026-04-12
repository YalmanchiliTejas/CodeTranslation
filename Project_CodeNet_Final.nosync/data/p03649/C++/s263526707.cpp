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
const LL LINF = (LL)1e18+20;
const double PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;

LL f(vector<LL>& v,LL N){
	LL ans = 0;
	while(1){
		LL kai = 0;
		for(int i=0;i<N;++i){
			LL cnt = v[i]/N;
			v[i] = v[i] - cnt*N - cnt;//+cnt分
			kai += cnt;
		}

		ans += kai;

		LL MAX = 0;
		for(int i=0;i<N;++i){
			v[i] += kai;
			MAX = max(MAX,v[i]);
		}
		
		if( MAX >= N ){
			continue;
		}else{
			break;
		}
	}
	return ans;
}
void solve(){
	int N;
	cin >> N;
	vector<LL> A(N);
	LL sum = 0;
	for(int i=0;i<N;++i){
		cin >> A[i];
		sum += A[i];
	}
	LL temp = f(A,N);
	cout << temp << endl;
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