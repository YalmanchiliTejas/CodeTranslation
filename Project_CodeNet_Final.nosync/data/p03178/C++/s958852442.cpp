#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)2e5+5)
#define MOD ((int)1e9 + 7) 
#define ll long long
#define _ << " " <<
#define TRACE(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"

int n,m,t;
int k[MAXN];
int dp[(int)1e4+5][105][2];
// dp [idx][%D][tight]
string s;
int ct;

int add(int&a,int b)
{
	a+=b;
	if(a>MOD)
		a-=MOD;
	if(a<0)
		a+=MOD;
	return a;
}

int rec(int idx,int sum,int tight=true)
{
	if(dp[idx][sum][tight] != -1) return dp[idx][sum][tight];
	if(idx == s.size())
	{
		if((sum%m) == 0)
			return dp[idx][sum][tight] = 1;
		return dp[idx][sum][tight] = 0;
	}

	int res=0;
	if(tight)
	{
		for (int i = 0; i < k[idx]; ++i)
			add(res,rec(idx+1,(sum+i)%m,false));
		add(res,rec(idx+1,(sum+k[idx])%m,true));
	}
	else
	{
		for (int i = 0; i <= 9; ++i)
			add(res,rec(idx+1,(sum+i)%m,false));
	}
	return dp[idx][sum][tight] = res;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	// clock_t tStart = clock();
	cin >> s >> m;

	for (int i = 0; i <= (int)s.size(); ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			dp[i][j][0] = -1; 
			dp[i][j][1] = -1; 
		}
	}

	for (int i = 0; i < (int)s.size(); ++i)
		k[i] = s[i] - '0';
	int a = rec(0,0,1);
	cout << a-1 << endl;//counts 0
	// printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
