#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<time.h>
#include<utility>
#include<vector>
using namespace std;
const long mod = 1000000007;
//以下、グローバル変数

long patty[51]; //レベルNバーガーのパティの数
long burger[51];//レベルNバーガーのパティとバンズの数

void precal() {
	patty[0] = 1; burger[0] = 1;
	for (int i = 1; i <= 50; i++) patty[i] = 2 * patty[i - 1] + 1;
	for (int i = 1; i <= 50; i++) burger[i] = 2 * burger[i - 1] + 3;
}

long solve(long N,long X){//レベルNバーガーの下からX枚のパティの数

    if (X == 0) return 0;
	if (N == 0) return 1;
    
	if (X > burger[N] / 2 + 1) return solve(N - 1, X - burger[N] / 2 - 1) + 1 + patty[N - 1];
	if (X == burger[N] / 2 + 1)return 1 + patty[N - 1];
	if (X < burger[N] / 2 + 1) return solve(N - 1, X - 1);
	if (true) return 0;
}

//--------------------

int main() {

	long N, X; cin >> N >> X;
	precal();

	cout << solve(N, X) << endl;

}