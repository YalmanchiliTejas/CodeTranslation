#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn=1e4+10,Maxd=1e2+10,MOD=1e9+7;
string K;
int D;
int Sum=0;
int Dp[Maxn][Maxd];
signed main()
{
	cin>>K>>D;
	int N=K.length();
	for(int i=1;i<=N;i++)
	{
		int Num=(int)K[i-1]-'0';
		for(int j=0;j<Num;j++)
		{
			++Dp[i][(Sum+j)%D];
		}
		Sum+=Num;
	}
	++Dp[N][Sum%D];
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<D;j++)
		{
			for(int denum=0;denum<10;denum++)
			{
				(Dp[i][j]+=Dp[i-1][((j-denum)%D+D)%D])%=MOD;
			}
		}
	}
	cout<<(Dp[N][0]-1+MOD)%MOD<<endl;
	return 0;
}