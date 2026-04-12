#include<bits/stdc++.h>
using namespace std;
string S;
int memo[10005][105][2];
const int MOD=1e9+7;
int m;
int solve(int ix, int sisa, bool con)
{
	if(ix==S.size())
	{
		if(sisa%m==0) return 1;
		return 0;
	}
	if(memo[ix][sisa][con]!=-1) return memo[ix][sisa][con];
	int ret=0;
	if(!con)
	{
		for(int z=0;z<10;z++)
		{
			int tmp=(sisa+z)%m;
			ret+=solve(ix+1, tmp, con);
			ret%=MOD;
		}
	}
	else
	{
		int tr=S[ix]-'0';
		for(int z=0;z<=tr;z++)
		{
			int tmp=(sisa+z)%m;
			if(z==tr) ret+=solve(ix+1, tmp, 1);
			else ret+=solve(ix+1, tmp, 0);
			ret%=MOD;
		}
	}
	return memo[ix][sisa][con]=ret;
}

int main()
{
	cin>>S;
	cin>>m;
	memset(memo, -1, sizeof(memo));
	printf("%d\n", (solve(0, 0, 1)-1+MOD)%MOD);
	return 0;
}