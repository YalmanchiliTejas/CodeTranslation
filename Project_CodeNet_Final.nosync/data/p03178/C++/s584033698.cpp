#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define int      long long int
#define MOD      1000000007
#define pb       push_back
#define pf		 push_front
#define vi       vector<int>
#define mi  	 map<int,int>
#define umi		 unordered_map<int,int>
#define pii      pair<int,int>
#define ff 		 first
#define ss 		 second
#define inf		 1e18
#define case	int t;cin>>t;while(t--)
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void pre()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
string s;
int d;
int dp[10007][2][103] = {0};
int fn(int id = 0, int tgt = 1, int sm = 0)
{	if (id == s.size())
		return sm == 0;

	if (dp[id][tgt][sm] != -1)
		return dp[id][tgt][sm];
	if (tgt == 1)
	{	int rs = 0;
		for (int i = 0; i <= s[id] - '0'; i++)
		{	rs += fn(id + 1, i == (s[id] - '0'), (sm + i) % d);
			rs %= MOD;
		}
		dp[id][tgt][sm] = rs;
		return rs;
	}
	else
	{	int rs = 0;
		for (int i = 0; i <= 9; i++)
		{	rs += fn(id + 1, 0, (sm + i) % d);
			rs %= MOD;
		}
		dp[id][tgt][sm] = rs;
		return rs;
	}
}
int32_t main()
{	pre();
//case
	{	cin >> s >> d;
		memset(dp, -1, sizeof(dp));
		int a1 = fn();
		cout << (a1 - 1 + MOD) % MOD << endl;
	}
	return 0;
}