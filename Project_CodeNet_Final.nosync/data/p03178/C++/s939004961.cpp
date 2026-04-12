#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <cstring>
#include <climits>
#include <iomanip>
using namespace std;

#define FORN(i, j, k) for(int i=j;i<k;i++)
#define FORR(i, j, k) for(int i=j;i>=k;i--)
#define REP(i, n) FORN(i, 0, n)
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

const int MODO = 1e+9 + 7;
const int INF = 1e18L;

string k;
int d,n;
int dp[100001][101][2];

int apply_mod(int a){
		if(a>=MODO){
				a -= MODO;
		}
		return a;
}

int solve(int idx, int sum, bool prev_smaller){
	if(idx == n){
		return sum == 0;
	}
	
	if(dp[idx][sum][prev_smaller] != -1){
		return dp[idx][sum][prev_smaller];
	}
	
	int digit = prev_smaller ? 9 : (k[idx]-'0');
	
	int res = 0;
	REP(i, digit+1){
		res += solve(idx+1, (sum + i)%d, (prev_smaller || (i<digit && !prev_smaller)));
		res = apply_mod(res);
	}
	return dp[idx][sum][prev_smaller] = res;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k;
	cin >> d;
	n = k.length();
	memset(dp, -1, sizeof(dp));
	cout << apply_mod(solve(0, 0, false) + MODO - 1) << endl;
	return 0;
}
