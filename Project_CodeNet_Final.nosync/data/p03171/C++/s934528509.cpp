#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <chrono>
#include <queue>
#include <string>
#include <cassert>
#include <bitset>
#include <stack> 

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 1000000007
#define BASE 77747
#define PI acos(-1.0)
#define MAXLEN 29

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef vector <ll> vll;

int n;
ll arr[3000];
ll dp[3000][3000];


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", arr + i);
	for (int i = 0; i < n; i++) 
		dp[i][i] = arr[i];
	for (int j = 2; j <= n; j++) {
		for (int i = 0; j + i <= n; i++) {
			dp[i][i + j - 1]= max(-dp[i + 1][i + j - 1] + arr[i], 
				-dp[i][i + j - 2] + arr[i + j - 1]);
			
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}