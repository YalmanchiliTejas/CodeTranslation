#include<bits/stdc++.h>
using namespace std;
int DP[10010][100][2];
int main()
{
	string S;
	int N;
	cin>>S>>N;
	DP[0][0][1]=1;
	for(int i=0;i<S.length();i++)
		for(int j=0;j<N;j++)
		{
			for(int k=0;k<10;k++)
				DP[i+1][(j+k)%N][0]=(DP[i+1][(j+k)%N][0]+DP[i][j][0])%1000000007;
			for(int k=0;k<S[i]-'0';k++)
				DP[i+1][(j+k)%N][0]=(DP[i+1][(j+k)%N][0]+DP[i][j][1])%1000000007;
			DP[i+1][(j+S[i]-'0')%N][1]=(DP[i+1][(j+S[i]-'0')%N][1]+DP[i][j][1])%1000000007;
		}
	cout<<(DP[S.length()][0][0]+DP[S.length()][0][1]+1000000006)%1000000007;
	return 0;
}