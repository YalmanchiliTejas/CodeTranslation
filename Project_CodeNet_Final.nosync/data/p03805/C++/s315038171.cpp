#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>
#include<set>
 
using namespace std;
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define F(i,j,k) fill(i[0],i[0]+j*j,k)
#define P(p) cout<<(p)<<endl;
#define INF 1<<25
 
typedef long long ll;

int dy[8]={1,1,1,0,0,-1,-1,-1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
struct S{
	int a,b,c;
};
bool asc(const S& left,const S& right){
	return left.c > right.c;
}
bool G[8][8];
bool visited[8];
int ans;
int N,M;
void dfs(int now){
	bool c=true;
	rep(i,N){
		if(visited[i]==false)
			c=false;
	}
	if(c){
		ans++;
	}
	rep(i,N){
		if(G[now][i]==true&&visited[i]==false){
			visited[i]=true;
			dfs(i);
			visited[i]=false;
		}
	}
}
int main(){
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a][b]=true;
		G[b][a]=true;
	}
	rep(i,N)visited[i]=false;
	visited[0]=true;
	dfs(0);
	cout<<ans<<endl;
	
	return 0;
}

