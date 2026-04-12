#include<iostream>
#include<algorithm>
using lint=long long;
using namespace std;

const int mod=1e9+7;
string K;
int D;
int dp[10010][2][110];

int rec(int dgt,int isless,int d)
{
	if(dgt==K.length())
		return d==0;
	
	if(dp[dgt][isless][d]!=-1)
		return dp[dgt][isless][d];
	
	int res=0;
	int maxnd;
	if(isless)maxnd=9;
	else maxnd=K[dgt]-'0';
	for(int nd=0;nd<=maxnd;nd++)
	{
		int nisless;
		if(isless==1 || nd<maxnd)nisless=1;
		else nisless=0;
		res+=rec(dgt+1,nisless,(d+nd)%D);
		res%=mod;
	}
	
	dp[dgt][isless][d]=res;
	return res;
}

int main()
{	
	cin >> K >> D;
	
	for(int i=0;i<10010;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<110;k++)
				dp[i][j][k]=-1;
	
	cout << (rec(0,0,0)-1+mod)%mod << endl;
	
	return 0;
}