#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct custom_hash 
{
    static unsigned long long splitmix64(unsigned long long x) 
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(unsigned long long x) const 
    {
        static const unsigned long long FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int maxn = 2e5 + 3; 
const long long inf = 1e18; 

int n;
int a[maxn];
void read()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}

long long dp[maxn][2][2];
void solve()
{
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = -inf;

	dp[1][0][0] = a[1], dp[1][1][0] = a[2], dp[1][0][1] = 0; 
    for (int i = 2; i <= n / 2; i++)
    {
    	dp[i][0][0] = dp[i-1][0][0] + a[i*2-1];
    	dp[i][1][0] = max(dp[i-1][0][0], dp[i-1][1][0]) + a[i*2];
    	dp[i][1][1] = max(dp[i-1][0][1], dp[i-1][1][1]) + a[i*2];
    	dp[i][0][1] = max(dp[i-1][0][1] + a[i*2-1], max(dp[i-1][0][0], dp[i-1][1][0])); 
    }

    if (n % 2 == 0)
    	cout << max(dp[n/2][0][0], dp[n/2][1][0]) << endl; 

    else 
    	cout << max(dp[n/2][0][0], max(dp[n/2][1][0], a[n] + dp[n/2][0][1])) << endl; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	read();
	solve();
}