/*----------------by syr----------------*/
/*
  -----  -----  -----
  |   |  |---|    _/
  |   |  | \_    /
  -----  |   \  -----

  |---\  \   /  |\  /|
  |   |   \_/   | \/ |
  |   |   / \   |    |
  |---/  /   \  |    |
*/
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;

const int INF=1e9+7;
const int maxn=3005;

int n;
int a[maxn];
ll dp[maxn][maxn];

int main(){
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d",a+i);
	FOR(len,0,n){
		FOR(i,0,n){
			int j=i+len;
			if(j>=n) continue;
			if(!len){
				if(n&1) dp[i][j]=a[i];
				else dp[i][j]=-a[i];
				continue;
			}
			if((n-len)&1){
				if(i+1<n) dp[i][j]=dp[i+1][j]+a[i];
				if(j-1>=0) dp[i][j]=max(dp[i][j],dp[i][j-1]+a[j]);
			}else{
				if(i+1<n) dp[i][j]=dp[i+1][j]-a[i];
				if(j-1>=0) dp[i][j]=min(dp[i][j],dp[i][j-1]-a[j]);
			}
		}
	}
	printf("%lld",dp[0][n-1]);
	return 0;
}
