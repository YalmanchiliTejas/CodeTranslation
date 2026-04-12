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
const long long llinf=9223372036854775807ll;
//int & long long
long long n,a[3005],dp[3005][3005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],dp[i][i]=a[i];
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
	cout<<dp[1][n];
	return 0;
}