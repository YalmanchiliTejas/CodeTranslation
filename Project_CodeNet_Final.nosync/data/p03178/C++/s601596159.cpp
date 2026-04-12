#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

typedef long long ll;

string k;
int n, d;
ll f[2][101][10101]; 

int main()
{
	cin>>k>>d;
	n=k.size();
	f[0][0][0]=1;
	f[1][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<d;j++)
		{
			f[1][j][i]%=mod;
			f[0][j][i]%=mod;
			for(int b=0;b<=9;b++)
			{
				if(b==(k[n-i-1]-48))	f[1][(j+b)%d][i+1]+=f[1][j][i];	
				if(b<(k[n-i-1]-48))		f[1][(j+b)%d][i+1]+=f[0][j][i];
				f[0][(j+b)%d][i+1]+=f[0][j][i];
			}		
		}
	}
	cout<<((f[1][0][n]-1)+mod)%mod;
}