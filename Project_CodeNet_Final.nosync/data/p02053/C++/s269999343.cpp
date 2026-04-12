#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))

#define DEBUG(x) cout<<#x<<": "<<(x)<<endl

int h,w;
char c[1252][1252];

int main(){
	scanf("%d%d",&h,&w);
	REP(i,h)scanf("%s",c[i]);
	int ans = 0;
	{
		int mn=1e9, mx=-1e9;
		REP(i,h)REP(j,w)if(c[i][j]=='B'){
			CHMIN(mn,i+j);
			CHMAX(mx,i+j);
		}
		CHMAX(ans, mx-mn);
	}
	{
		int mn=1e9, mx=-1e9;
		REP(i,h)REP(j,w)if(c[i][j]=='B'){
			CHMIN(mn,i-j);
			CHMAX(mx,i-j);
		}
		CHMAX(ans, mx-mn);
	}
	printf("%d\n",ans);
	return 0;
}
