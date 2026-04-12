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
LL a[3000],dp[3000][3000];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(9);

	cin >> N;
	for(int i=0; i<N; i++) cin >> a[i];

	for(int l=N-1; l>=0; l--){
		for(int r=0; r<N; r++){
			if(l > r) dp[l][r] = 0;
			else{
				if((l+N-r+1)%2 == 0) dp[l][r] = max(a[l]+dp[l+1][r], a[r]+dp[l][r-1]);
				else dp[l][r] = min(-a[l]+dp[l+1][r], -a[r]+dp[l][r-1]);
			}
		}
	}
	cout << dp[0][N-1] << endl;

	return 0;
}
