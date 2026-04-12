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

int N,M;
LL ans = 0;
bool already[8] = {};
bool can[8][8] = {};

void dfs(int now){
	bool flg = true;
	for(int i=0; i<N; i++){
		flg = flg && already[i];
		if(!already[i] && can[now][i]){
			already[i] = true;
			dfs(i);
			already[i] = false;
		}
	}
	if(flg) ans++;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(9);

	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a,b;
		cin >> a >> b;
		a--; b--;
		can[a][b] = true;
		can[b][a] = true;
	}
	for(int i=0; i<1; i++){
		already[i] = true;
		dfs(i);
		already[i] = false;
	}
	cout << ans << endl;

	return 0;
}
