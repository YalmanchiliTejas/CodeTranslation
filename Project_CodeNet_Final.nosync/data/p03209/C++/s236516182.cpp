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

long long int num[51] = {};
long long int patnum[51] = {};

long long int solve(int n, long long int x)
{
	if(x == 0) return 0;
	if(n == 0) return 1;
	if(x <= num[n - 1] + 1) return solve(n - 1, x - 1);
	else return patnum[n - 1] + solve(n - 1, x - num[n - 1] - 2) + 1;
}


int main()
{
	int n;
	long long int x;
	cin >> n >> x;

	num[0] = 1;
	patnum[0] = 1;
	for(int i = 1; i <= n; i++){
		num[i] = 2 * num[i - 1] + 3;
		patnum[i] = 2 * patnum[i - 1] + 1;
	}

	cout << solve(n, x) << endl;
	return 0;
}