#include<bits/stdc++.h>
#define MAX 3001
using namespace std;
long long N,MOD;
long long Dp[MAX][MAX];
long long Combination[MAX][MAX]; 
inline long long Quick_Power(long long A,long long P,long long MOD)
{
	register long long Return;
	Return=1;
	while(P)
	{
		if(P&1)
		{
			Return=Return*A%MOD;
		}
		A=A*A%MOD;
		P>>=1;
	}
	return Return;
}
int main(void)
{
	register long long i,j;
	cin>>N>>MOD;
	for(i=0;i<=N;i++)
	{
		Dp[i][0]=1;
		for(j=1;j<=i;j++)
		{
			Dp[i][j]=(Dp[i-1][j-1]+(j+1)*Dp[i-1][j]%MOD)%MOD;
		}
	}
	for(i=0;i<=N;i++)
	{
		Combination[i][0]=1;
		for(j=1;j<=i;j++)
		{
			Combination[i][j]=(Combination[i-1][j-1]+Combination[i-1][j])%MOD;
		}
	}
	register long long Ans;
	Ans=0;
	for(i=0;i<=N;i++)
	{
		register long long Can;
		Can=Quick_Power(2,Quick_Power(2,N-i,MOD-1),MOD);
		register long long Num;
		Num=Quick_Power(2,N-i,MOD);
		register long long Sum;
		Sum=0;
		register long long Coefficient;
		Coefficient=1;
		for(j=0;j<=i;j++)
		{
			Sum=(Sum+Dp[i][j]*Coefficient)%MOD;
			Coefficient=Coefficient*Num%MOD;
		}
		Ans=(Ans+Sum*(Can*(i&1?MOD-Combination[N][i]:Combination[N][i])%MOD)%MOD)%MOD;
	}
	cout<<Ans<<endl; 
	return 0;
}