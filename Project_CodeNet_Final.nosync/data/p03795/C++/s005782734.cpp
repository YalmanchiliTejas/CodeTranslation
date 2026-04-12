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
#include <random>
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
inline T gcd(T a, T b){return b ? gcd(b, a % b) : a;}
//inline T gcd(T a, T b){return b == 0 ? a : gcd(b, a % b);}
/*inline T gcd(T a,T b){
	while(b != 0 ){
		a = a % b;
		swap(a,b);
	}
	return a;
}*/

// 最小公倍数
template<class T>
inline T lcm(T a, T b){return a / gcd(a, b) * b;}
//inline T lcm(T a, T b){return a * b / gcd(a, b);}
////////////////////////////////

inline void solve(){
	int N;
	cin >> N;
	cout << N*800-200*(N/15) << endl;
}

signed main(void){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	//std::cout << std::fixed;//小数を10進数表示
	//cout << setprecision(16);//小数点以下の桁数を指定
	
	solve();
}
