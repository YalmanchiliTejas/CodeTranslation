#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pb push_back
#define pp pair<int,int>
#define rep(i,l,r) for(int i=l;i<r;i++)
#define int long long
#define mod 1000000007
string s;
int n;
int d;
int memo[10005][105][2];
int rec(int ind,int left,int rest)
{
	if(ind == n)
	{
		if(left == 0)  return 1;
		return 0;
	}
	if(memo[ind][left][rest]!=-1) return memo[ind][left][rest];
	int ans = 0;
	if(rest == 0)
	{
		rep(i,0,10)
		{
			ans += rec(ind+1,((left-i%d)%d+d)%d,0);
			ans %= mod;
		}
	}
	else
	{
		rep(i,0,s[ind]-'0')
		{
			
			ans += rec(ind+1,((left-i%d)%d+d)%d,0);
			ans %=mod;
		}
		ans += rec(ind+1,((left-(s[ind]-'0')%d)%d+d)%d,1);
		ans %=mod;
	}
	return memo[ind][left][rest] = ans;


}
 main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt.txt","r",stdin);
	// freopen("output.txt.txt","w",stdout);
	// #endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>s>>d;
	n = s.size();
	rep(i,0,n+1)
	{
		rep(j,0,d+1)
		{
			rep(k,0,2)
			memo[i][j][k] = -1;
		}

	}
	cout << (rec(0,0,1)+mod-1)%mod << endl;



}