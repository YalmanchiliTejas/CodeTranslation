// Created by Nandu Vinodan
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define vi vector<int>
#define pi pair<int, int>
#define INF INT_MAX
#define _INF INT_MIN
#define TC 0

using namespace std;
using ll = long long;
string num;
int dp[105][4][2];
int solve(int index, int nz, int small) {

	//db3(index, nz, small);
	if (index == num.length()) {
		return dp[index][nz][small] = (nz==0);
	}
	//if (index >= 10) return 0;
	if (dp[index][nz][small] != -1)
		return dp[index][nz][small];
	int limit  = (small ==  1 ? 9 : (num[index]-'0'));
	int res = 0;
	for (int i=0; i<=limit; i++) {
		int z = nz;
		if (i > 0) {
			if (z > 0) z--;
			else continue;
		}

		int s = small;
		if (s==0 && i < limit) s=1;

		res += solve(index+1, z, s);
	}
	return dp[index][nz][small] = res;
}

void testcase() {
	int K;
	cin >> num >> K;

	rep (i, 0, 104)
	rep (j, 0, 3)
	rep (k, 0, 1)
		dp[i][j][k] = -1;
    cout << solve(0, K, 0)  << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    if (TC)
        cin>>t;
    while(t--) {
        testcase();
    }
    return 0;
}