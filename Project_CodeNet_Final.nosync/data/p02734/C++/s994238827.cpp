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
lint dp[3010][3010];
lint mo=998244353;
int a[3010];
int main()
{
	int n,s;cin>>n>>s;lint out=0;
	rep(i,n) cin>>a[i];
	memset(dp,0,sizeof(dp));
	rep(i,n) dp[i][0]=i+1;
	rep(i,n){
		//dp[i+1][0]=dp[i][0]+1;
		rep(j,s+1){
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			if(j>0) dp[i+1][j]+=dp[i][j];dp[i+1][j]%=mo;
			if(j+a[i]>s) continue;
			if(j+a[i]==s){
				out+=dp[i][j]*(n-i);out%=mo;
			}
			else{
				dp[i+1][j+a[i]]+=dp[i][j];
				dp[i+1][j+a[i]]%=mo;
			}
		}
	}
	cout<<out<<endl;
}
