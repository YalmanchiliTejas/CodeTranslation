#include<iostream>
#include<vector>
#include<map>
#include<queue>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const double inf=1e8;	
int main(){
	int n,m,r;
	cin>>n>>m>>r;
	vi a(m);
	rep(i,m)cin>>a[i];
	map<int,int>ma;
	rep(i,m)ma[a[i]]=i+1;
	vvi in(n,vi(r));
	rep(i,n)rep(j,r)cin>>in[i][j];
	int N=1<<m;
	vi dp(N,inf);
	dp[N-1]=0;
	queue<int>q;
	q.push(N-1);
	while(!q.empty()){
		int b=q.front();q.pop();
		rep(k,r){
			int w=0;
			rep(i,m)if(b&1<<i&&ma[in[a[i]-1][k]])w|=1<<(ma[in[a[i]-1][k]]-1);
			if(dp[w]>dp[b]+1){
				dp[w]=dp[b]+1;
				q.push(w);
			}
		}
	}
	cout<<dp[0]<<endl;
}