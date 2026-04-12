#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
//問題文および制約はちゃんと確認しよう！
//サイズは10^5じゃなくて2×10^5とかかもしれないし、重要な制約・条件を見落としているかも
//とりあえずサンプルを読んでから解法を考えよう？
lint dp[200100][10];
lint inf=12345678901234567LL;
lint a[200100];
int main()
{
	int n;
	cin>>n;rep(i,n) cin>>a[i];a[n]=-inf;a[n+1]=0;
	rep(i,n+10) rep(j,8) dp[i][j]=-inf;
	//dp[0][0]=0;
	int lim=(n%2)+1;
	rep(i,lim+1) dp[i][i]=a[i];
	//cout<<dp[2][2]<<endl;
	rep(i,n) rep(j,lim+1) rep(k,lim-j+1){
		dp[i+k+2][j+k]=max(dp[i+k+2][j+k],dp[i][j]+a[i+k+2]);
	}
	rep(i,n) rep(j,lim+1){
		//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
	}
	lint out=-inf;
	rep(i,lim+1) out=max(out,dp[n+1][i]);
	cout<<out<<endl;
}
