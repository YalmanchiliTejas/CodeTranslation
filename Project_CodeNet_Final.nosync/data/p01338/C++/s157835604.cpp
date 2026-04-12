#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<numeric>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>

#define rep(i,n) for(int i=0;i<n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define rp(i,c) rep(i,(c).size())
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf=1<<28;
const double INF=1e12,EPS=1e-9;

int score[]={0,0,60,70,80};
int tb[5][5], dp[4][1<<2*4];

int main()
{
	int n; scanf("%d",&n);
	rep(i,n)
	{
		rep(i,5)rep(j,5)scanf("%d",tb[i]+j);
		rep(i,4)rep(j,1<<2*4)dp[i][j]=0;
		
		rep(i,1<<2*4){
			dp[0][i]=0;
			rep(j,5)if(tb[0][j]){
				int sc=tb[0][j];
				if(j>0)sc+=i>>2*j-2&3;
				if(j<4)sc+=i>>2*j&3;
				while(sc>4)sc-=4;
				
				dp[0][i]+=score[sc];
			}
		}
		
		for(int i=1;i<4;i++)rep(j,1<<2*4)rep(jj,1<<2*4){
			int sum=dp[i-1][j];
			rep(k,5)if(tb[i][k]){
				int sc=tb[i][k];
				if(k>0)sc+=(j>>2*k-2&3) + (jj>>2*k-2&3);
				if(k<4)sc+=(j>>2*k&3) + (jj>>2*k&3);
				while(sc>4)sc-=4;
				
				sum+=score[sc];
			}
			dp[i][jj]=max(dp[i][jj],sum);
		}
		
		int ans=0;
		rep(i,1<<2*4){
			int sum=dp[3][i];
			rep(j,5)if(tb[4][j]){
				int sc=tb[4][j];
				if(j>0)sc+=i>>2*j-2&3;
				if(j<4)sc+=i>>2*j&3;
				while(sc>4)sc-=4;
				
				sum+=score[sc];
			}
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}