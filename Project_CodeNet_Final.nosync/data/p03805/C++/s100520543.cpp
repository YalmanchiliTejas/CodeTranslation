#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef pair<int,int> Pi;
typedef long long int ll;
const int INF=(ll)(1<<30)-1;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int n,m;
bool ab[10][10];

int dfs(int v,int N,bool visit[10]){
	bool alv=true;
	int ans;
	for(int i=0;i<n;i++){
		if(!visit[i]){
			alv=false;
		}
	}
	if(alv){
		return 1;
	}
	int ret=0;
	for(int i=0;i<n;i++){
		if(!ab[v][i])continue;
		if(visit[i])continue;
		
		visit[i]=true;
		ret+=dfs(i,N,visit);
		visit[i]=false;
	}
	return ret;
}

int main(){
	cin>>n>>m;
	REP(i,m){
		int t,s;
		cin>>t>>s;
		t--,s--;
		ab[t][s]=true;
		ab[s][t]=true;
	}
	bool visit[n];
	REP(i,n)
		visit[i]=false;
	visit[0]=true;
	cout<<dfs(0,n,visit)<<endl;
	return 0;
}
	