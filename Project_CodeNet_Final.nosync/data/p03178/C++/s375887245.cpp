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

const LL MOD = 1e9 + 7;
const int N = 1e5;
const int D = 100;
LL dp[2][N + 5][D + 5];

string s;
int d;

LL calc(int issame, int idx,int sisa) {
	if(idx == s.size()) return (sisa == 0);
	LL &res = dp[issame][idx][sisa];
	if(res != -1) return res;
	res = 0;
	int x = s[idx] - '0';
	if(issame == 0) x = 9;
	for(int i = 0;i <= x;i++) {
		res = (res + calc(issame & (i == x), idx + 1, (sisa + i) % d)) % MOD;
	}
	return res;
}

void hora(int tc) {
	cin>>s>>d;
	memset(dp,-1,sizeof dp);
	cout<<(calc(1,0,0) + MOD - 1) % MOD<<endl;	
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}

