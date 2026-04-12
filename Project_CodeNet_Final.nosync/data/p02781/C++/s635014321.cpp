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
string s;int K,n;
lint dp[110][5][2];
int main()
{
	cin>>s;cin>>K;
	n=s.size();
	//reverse(All(s));
	memset(dp,false,sizeof(dp));
	dp[0][0][0]=1;
	rep(i,n) rep(j,K+1){
		//cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
		rep(k,10){
			int nj=j;if(k>0) nj++;
			if(k<(s[i]-'0')){
				//cout<<'a'<<endl;
				dp[i+1][nj][1]+=dp[i][j][0]+dp[i][j][1];
			}
			else if(k>(s[i]-'0')){
				dp[i+1][nj][1]+=dp[i][j][1];
			}
			else{
				dp[i+1][nj][1]+=dp[i][j][1];
				dp[i+1][nj][0]+=dp[i][j][0];
			}
		}
	}
	lint out=dp[n][K][0]+dp[n][K][1];
	cout<<out<<endl;
}
