#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
typedef vector<vector<lli> > vvi;
typedef vector<ii> vii;

#define EB emplace_back
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

const lli mod = 1e9 +7;
lli d, dp[10002][2][2][101];
string l="1", r;

lli solve(int level, int tlo, int thi, int rem)
{
	if(level>=r.size()){
		if(rem==0) return 1;
		return 0;
	}
	if(dp[level][tlo][thi][rem]==-1){
		int blo=0, bhi=9;
		lli ans=0;
		if(tlo==1)
			blo = l[level]-'0';
		if(thi==1)
			bhi = r[level]-'0';
		for(int i=blo; i<=bhi; i++)
		{
			int nlo=tlo, nhi=thi;
			if(i>l[level]-'0')
				nlo=0;
			if(i<r[level]-'0')
				nhi=0;
			ans += solve(level+1, nlo, nhi, (rem+i)%d);
			ans %= mod;
		}
		dp[level][tlo][thi][rem] = ans;
	}
	return dp[level][tlo][thi][rem];
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> r >> d;
	while(l.size()<r.size())
		l+='0';
	reverse(l.begin(), l.end());
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1, 1, 0);
}