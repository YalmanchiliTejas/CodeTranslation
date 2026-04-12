#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;

template<class T> inline void checkmin(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,const T &b){if(b>a) a=b;}

const int maxn=2e3+10; 
const int inf=1e9+10;

int dp[maxn][maxn],n,a[maxn*3],f[maxn],maxval=-inf,cnt=0;
vector <pair<pair<int,int>,int> > v;

int main(){
	scanf("%d",&n);
	for(int i=0;i<3*n;i++) scanf("%d",&a[i]);
	for(int i=0;i<maxn;i++) for(int j=0;j<maxn;j++) dp[i][j]=-inf;
	for(int i=0;i<maxn;i++) f[i]=-inf;
	
	dp[a[0]][a[1]]=0; dp[a[1]][a[0]]=0; 
	f[a[0]]=0; f[a[1]]=0; maxval=0;
	for(int i=2;i+3<=3*n;i+=3){
		sort(a+i,a+i+3);
		int na=a[i],nb=a[i+1],nc=a[i+2];
		if(na==nb&&nb==nc){ cnt++; continue; }
		v.clear();
		if(na==nb) for(int j=1;j<=n;j++) v.pb(mp(mp(j,nc),dp[na][j]+1));
		else if(nb==nc) for(int j=1;j<=n;j++) v.pb(mp(mp(j,na),dp[nb][j]+1));
		v.pb(mp(mp(na,nb),dp[nc][nc]+1)); 
		v.pb(mp(mp(nb,nc),dp[na][na]+1));
		v.pb(mp(mp(na,nc),dp[nb][nb]+1)); 
		v.pb(mp(mp(na,nb),maxval)); v.pb(mp(mp(na,nc),maxval));  v.pb(mp(mp(nb,nc),maxval));
		for(int j=1;j<=n;j++) for(int k=i;k<i+3;k++) v.pb(mp(mp(j,a[k]),f[j]));
		for(int j=0;j<v.size();j++){
			int x=v[j].fst.fst,y=v[j].fst.snd,val=v[j].snd;
			checkmax(dp[x][y],val); checkmax(dp[y][x],val);
			checkmax(maxval,val); checkmax(f[x],val); checkmax(f[y],val);
		}
	}
	dp[a[n*3-1]][a[n*3-1]]++;
	int ans=0;
//	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<i<<","<<j<<","<<dp[i][j]<<endl;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) checkmax(ans,dp[i][j]);
	printf("%d\n",ans+cnt);
	return 0;
}