#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
int N,M;
bool G[8][8];
bool vis[1000][8];
bool rvis[8];
int ans=0;
int k=0;

void dfs(int x){
	k++;
	bool F=true;
	rvis[x]=true;
	REP(i,8)
	vis[k][i]=rvis[i];

	REP(i,N){
		if(G[x][i] && !rvis[i])
			dfs(i);
	}
	REP(i,N){
		if(!vis[k][i])F=false;
		//if(co>1)vis[i]=rvis[i];
	}
	k--;
	REP(i,8)rvis[i]=vis[k][i];
	if(F)ans++;
	return;
}

int main(){
cin.tie(0);
ios::sync_with_stdio(false);

	REP(i,1000){
		REP(j,8)
			vis[i][j]=false;
	}
	REP(i,8)rvis[i]=false;
	cin>>N>>M;
	VI A(M);
	VI B(M);
	REP(i,8){
		REP(j,8)G[i][j]=false;
	}
	REP(i,M){
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		G[A[i]][B[i]]=true;
		G[B[i]][A[i]]=true;
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
