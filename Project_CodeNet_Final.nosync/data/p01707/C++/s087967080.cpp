#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
#define MOD 1000000007ll
ll dp[2050][2050];
int N,X;
ll D;
ll mod_pow(ll a,ll x)
{
	ll res =1ll;
	if(x==0ll)return res;
	while(x>0)
	{
		if(x&1)res = (res*a)%MOD;
		a = (a*a)%MOD;
		x >>= 1;
	}
	return res;
}
int main()
{
	while(1)
	{
		cin >> N >> D >> X;
		if(N==0&&D==0&&X==0)break;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1ll;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				dp[i+1][j+1]=(dp[i][j]+dp[i+1][j])%MOD;
				if(j-X+1>=0)dp[i+1][j+1]=(dp[i+1][j+1]-dp[i][j-X+1]+MOD)%MOD;
			}
		}
		ll ans = 0ll;
		ll C = D%MOD;
		for(int i=1;i<=min(D,(ll)N);i++)
		{
			ans = (ans+C*dp[i][N])%MOD;
			C = (C*((D-i)%MOD))%MOD;
			C = (C*mod_pow(i+1,MOD-2))%MOD;
		}
		cout << ans << endl;
	}
	return 0;
}