#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#include<set>
#include<random>
#include<map>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 11451419198109130;
typedef pair<int, int> P;
typedef pair<int,P> PP;
struct edge { int to, cor; };

int a[3005];
int dp[3005][3005];
int n; 
int memo(int l, int r) {//[l,r]
	if (dp[l][r])return dp[l][r];
	int res;
	if ((((r - l + 1 )) & 1)==(n&1)) {//先手
		if (r == l) {
			res = a[l];
		}
		else {
			res = max(a[l] + memo(l + 1, r), a[r] + memo(l, r - 1));
		}
	}
	else {
		if (r == l) {
			res = 0;
		}
		else res = min(memo(l + 1, r) , memo(l, r - 1));
	}
	return dp[l][r] = res;
}

signed main() {
	cin >> n;
	rep(i, n)cin >> a[i];

	int sum=memo(0, n - 1);
	int asum = 0;
	rep(i, n)asum += a[i];
	
	cout << sum *2- asum << endl;
}