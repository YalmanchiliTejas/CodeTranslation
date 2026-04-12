#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define f first
#define s second

#define MM INT_MAX/5
#define MIM INT_MIN/2

int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,1,-1 };

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define v vector
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

#define MAX 3001

v<int> values;
ll dp[MAX][MAX];

int main()
{
	int N;
	cin >> N;
	values.assign(N, 0);
	for (int i = 0; i < N; i++)
		cin >> values[i];
	for (int i = 0; i < N; i++)
		dp[i][i] = values[i];
	for (int size = 2; size <= N; size++)
		for (int l = 0;  l + size - 1 < N; l++)
		{
			int r = size + l - 1;
			dp[l][r] = max(values[l] - dp[l + 1][r], values[r] - dp[l][r - 1]);
		}
	cout << dp[0][N - 1];
}
