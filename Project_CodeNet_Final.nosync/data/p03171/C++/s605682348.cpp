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

const int N = 3000;
LL dp[2][N + 5][N + 5];
bool vis[2][N + 5][N + 5];
LL arr[N + 5];
int n;

LL solve(int one,int idx,int dpn) {
	if(idx == n) return 0;
	if(vis[one][idx][dpn] == true) return dp[one][idx][dpn];
	vis[one][idx][dpn] = 1;
	int blkg = n - 1 - (idx - dpn);
	if(one == 1) {
		dp[one][idx][dpn] = -1e18;
		dp[one][idx][dpn] = max(arr[dpn] - solve(!one, idx + 1,dpn + 1), arr[blkg] - solve(!one, idx + 1, dpn));
	}
	else {
		dp[one][idx][dpn] = 1e18;
		dp[one][idx][dpn] = max(arr[dpn] - solve(!one, idx + 1,dpn + 1), arr[blkg] - solve(!one, idx + 1, dpn));
	}
	return dp[one][idx][dpn];
}

void hora(int tc) {
	cin>>n;
	for(int i = 0;i < n;i++) cin>>arr[i];
	memset(vis,0,sizeof vis);
	cout<<solve(1,0,0)<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}

