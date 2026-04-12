#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int MAXK = 10005;
const int MAXD = 105;

ll d, dp[MAXK][MAXD][2][2], mod = 1e9 + 7;
string a, b;

ll rec(ll pos, ll rem, bool flag1, bool flag2)
{
	if(dp[pos][rem][flag1][flag2] != -1) return dp[pos][rem][flag1][flag2];
	if(pos == a.length()) return !rem;
	ll ans = 0, start1 = 0, end1 = 9;
	if(!flag1) start1 = a[pos] - '0';
	if(!flag2) end1 = b[pos] - '0';
	for(int i=start1;i<=end1;i++)
	{
		ans = (ans + rec(pos + 1, (rem + i) % d, (flag1 | i > start1), (flag2 | i < end1))) % mod;
	}
	return dp[pos][rem][flag1][flag2] = ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> b >> d;
	a = "";
	for(int i=0;i<b.length() - 1;i++) a += '0';
	a += '1'; 
	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0, 0, 0) << endl;
    return 0;
}  