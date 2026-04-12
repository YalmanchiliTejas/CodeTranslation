#include<functional>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<string>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};// 上 左 下 右
const int N=100005,M=1000005,K=200005,mod=1000000007;
const long long llinf=922337206854775807ll;
//int & long long
string s;
long long n,dp[10005][105][2],ns;
inline long long f(char c)
{
	return int(c-'0');
}
int main(){
	cin>>s>>n;
	ns=f(s[0]);
	dp[0][ns%n][1]++;
	for(long long i=0;i<f(s[0]);i++)
		dp[0][i%n][0]++;
	for(long long i=1;i<s.size();i++)
	{
		ns+=f(s[i]);
		for(long long j=0;j<n;j++)
			for(long long k=0;k<=9;k++)
			{
				dp[i][(j+k)%n][0]=(dp[i][(j+k)%n][0]+dp[i-1][j][0])%mod;
				if(k<f(s[i]))
					dp[i][(j+k)%n][0]=(dp[i][(j+k)%n][0]+dp[i-1][j][1])%mod;
			}
		dp[i][ns%n][1]=1;
	}
	cout<<(dp[s.size()-1][0][0]+dp[s.size()-1][0][1]-1+mod)%mod;
	return 0;
}