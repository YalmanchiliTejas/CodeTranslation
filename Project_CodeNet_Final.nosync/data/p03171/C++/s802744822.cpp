#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>

using namespace std;

#define mod 1000000007
#define INIT mod * 3000

int n;
int a[3001];
long long int result[3001][3001][2];

long long int solve(int s, int t, bool isFirstTurn){
	if(result[s][t][isFirstTurn] != (long long int)INIT) return result[s][t][isFirstTurn];
	else if(s == t) return 0;
	if(isFirstTurn) result[s][t][isFirstTurn] = max(a[s] + solve(s + 1, t, !isFirstTurn), a[t - 1] + solve(s, t - 1, !isFirstTurn));
	else result[s][t][isFirstTurn] = min(-a[s] + solve(s + 1, t, !isFirstTurn), -a[t - 1] + solve(s, t - 1, !isFirstTurn));
	return result[s][t][isFirstTurn];
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j <= n; j++){
			result[i][j][0] = result[i][j][1] = (long long int)INIT;
		}
	}
	cout << solve(0, n, true) << endl;

}