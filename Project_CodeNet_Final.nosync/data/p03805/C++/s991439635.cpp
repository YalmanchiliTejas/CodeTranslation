#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define print(n) cout<<n<<endl
const int M=100111;
const int inf=1000000007;
const long long INF=1000000000000000007;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ddx[8]={1,-1,0,0,1,-1,-1,1},ddy[8]={0,0,1,-1,1,-1,1,-1};

int n,m,a,b;
vi v[10];
bool flag[10]={};
int dfs(int now,int depth){	
	if(flag[now])return 0;	
	if(depth==n)return 1;	
	flag[now]=true;			
	int ans=0;	
	for(auto vv:v[now])ans+=dfs(vv,depth+1);
	flag[now]=false;
	return ans;
}

int main(){
	cin>>n>>m;
	rep(i,0,m){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	print(dfs(1,1));
}