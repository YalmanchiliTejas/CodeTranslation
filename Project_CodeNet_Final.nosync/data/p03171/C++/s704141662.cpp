#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define POWER9 1000000000
#define MOD POWER9+7
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define LL_MIN (LL)-9223372036854775807
#define LL_MAX (LL)9223372036854775807
#define PI 3.14159265359
int N;
LL a[3000];
LL dp[3000][3000];
LL solve(int l, int r){
	if(l > r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	int now = l+(N-r+1);
	if(now%2 == 0) return dp[l][r] = max(a[l]+solve(l+1,r),a[r]+solve(l,r-1));
	else return dp[l][r] = min(-a[l]+solve(l+1,r),-a[r]+solve(l,r-1));
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(9);

	cin >> N;
	for(int i=0; i<N; i++) cin >> a[i];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			dp[i][j] = -1;
		}
	}
	cout << solve(0,N-1) << endl;

	return 0;
}
