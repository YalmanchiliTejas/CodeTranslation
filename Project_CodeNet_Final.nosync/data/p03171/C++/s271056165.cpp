#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn=3010;
int N;
int A[Maxn];
int Dp[Maxn][Maxn];
signed main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
	}
	for(int dLen=1;dLen<=N;dLen++)
	{
		for(int Left=0;Left+dLen<=N;Left++)
		{
			int Right=Left+dLen;
			bool Turn=(N-dLen)%2;
			if(!Turn)
			{
				Dp[Left][Right]=max(Dp[Left][Right-1]+A[Right-1],Dp[Left+1][Right]+A[Left]);
			}
			else
			{
				Dp[Left][Right]=min(Dp[Left][Right-1]-A[Right-1],Dp[Left+1][Right]-A[Left]);
			}
		}
	}
	cout<<Dp[0][N]<<endl;
	return 0;
}