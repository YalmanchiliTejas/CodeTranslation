#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <utility>
#include <map>
#include <deque>
using namespace std;
#define rep(i,n) for(int i=1;i<=(int)(n);i++)
#define Rep(i,n) for(int i=0;i<=(int)(n-1);i++)
typedef long long ll;
typedef map<int,int> mint;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
typedef deque<pair<ll,ll>> dep;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int inf=1e9+1000;
ll infi=1e18+100;

//x=10111;
//x<<2 = 1011100 (右シフト),x>>2 = 101 (左シフト)
//(x>>2)&1 = 101 & 001 = 1
//iビット目は、(x>>i) & 1 でわかる(x>>i)%2 でもよい

const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v,int N,bool visited[nmax]){
	
	bool all_visited=true;
	
	Rep(i,N){
		if(visited[i]==false) all_visited=false;
	}
	
	if(all_visited){
		return 1;
	}
	
	int ret=0;
	
	Rep(i,N){
		if(graph[v][i]==false) continue; //以下の処理をスキップ
		if(visited[i]) continue;
		
		visited[i]=true;
		ret+=dfs(i,N,visited);
		visited[i]=false;
	}
	
	return ret;
	
}


int main(){
	
	int N,M;
	cin>>N>>M;
	Rep(i,M){
		int A,B;
		cin>>A>>B;
		graph[A-1][B-1]=true;
		graph[B-1][A-1]=true;
	}
	
	bool visited[nmax];
	Rep(i,N) visited[i]=false;
	visited[0]=true;
	
	cout<<dfs(0,N,visited)<<endl;
	
	  return 0;
  }
