#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

ll dp[20000][2][100];
int main(){
	string s;int d;cin>>s>>d;
	dp[0][0][0]=1;
	rep(i,s.size())rep(j,2)rep(k,d){
		int lim=(j==0?s[i]-'0':9);
		for(int t=0;t<=lim;t++){
			(dp[i+1][j||t<lim][(k+t)%d]+=dp[i][j][k])%=MOD;
		}
	}
	cout<<(dp[s.size()][0][0]+dp[s.size()][1][0]+MOD-1)%MOD<<endl;
}