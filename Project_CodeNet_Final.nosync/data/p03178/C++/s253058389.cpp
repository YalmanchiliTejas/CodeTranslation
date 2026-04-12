#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int M = 1e9 + 7, N = 1e4 + 7, D = 102;

int dp[N][D][2];
int a[N];

signed main()
{
	IO_OP;
	
	string s;
	int d;
	cin >> s >> d;
	for(int i=0;i<s.size();i++)
		a[i] = s[s.size()-i-1] - '0';
	dp[N-1][0][1] = 1;
	for(int i=N-1;i>0;i--) {
		for(int j=0;j<d;j++) {
			for(int k=0;k<2;k++) {
				if(dp[i][j][k] == 0) continue;
				if(k == 0) {
					for(int l=0;l<10;l++)
						(dp[i-1][(j+l)%d][0] += dp[i][j][k]) %= M;
				} else {
					int b = a[i-1];
					(dp[i-1][(j+b)%d][1] += dp[i][j][k]) %= M;
					for(int l=0;l<b;l++)
						(dp[i-1][(j+l)%d][0] += dp[i][j][k]) %= M;
				}
			}
		}
	}
	cout << (dp[0][0][0] + dp[0][0][1] + M - 1) % M << endl;
}



