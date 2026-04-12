#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef long long ll;
typedef pair<ll,ll>pi;
const int MAXN=3005;
const int MOD=998244353;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define fst first
#define snd second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define db(x) cerr<<#x<<" = "<<x<<"\n"
#define LOW(v,x) (lower_bound(all(v),(x))-(v).begin())
#define UP(v,x) (upper_bound(all(v),(x))-(v).begin())

int N,S,A[MAXN];
int dp[MAXN][MAXN][3];

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>S;
	FOR(i,1,N)cin>>A[i];
	dp[0][0][0]=1;
	FOR(i,1,N)FOR(j,0,S){
		(dp[i][j][0]+=dp[i-1][j][0])%=MOD;
		(dp[i][j][1]+=dp[i-1][j][0]+dp[i-1][j][1])%=MOD;
		(dp[i][j][2]+=dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%=MOD;
		if(A[i]<=j) {
			(dp[i][j][1]+=dp[i-1][j-A[i]][0]+dp[i-1][j-A[i]][1])%=MOD;
			(dp[i][j][2]+=dp[i-1][j-A[i]][0]+dp[i-1][j-A[i]][1])%=MOD;
		}
	}
	cout<<dp[N][S][2];	
}
