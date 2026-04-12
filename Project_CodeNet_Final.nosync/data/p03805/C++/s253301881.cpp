#include <algorithm>
#include <iostream>
#include <map>
#include <cstdio>
#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FORq(i, m, n) for(int i = m;i <= n;i++)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define PRINTD(n) printf("%d\n",n)
#define DEBUG printf("%s\n","debug")
using namespace std;
 /////////////////////////////////////////////////////
bool d[50][50]={};




int dfs(int v,int n,bool visited[]){
	bool allvisited = true;

	REP(i,n){
		if (visited[i] == false){
			allvisited = false;
		}
	}
	
	if (allvisited == true) {
		return 1;
	}
	
	int ret = 0;
		
	REP(j,n){
		if(d[v][j]==false) continue;
		if(visited[j]) continue;

			visited[j] = true;
			ret += dfs(j,n,visited);
			visited[j] = false;
	}
	
	return ret;
}

int main() {
	int n,m;
	SCD(n);
	SCD(m);


	REP(i,m){
		int a,b;
		SCD(a);
		SCD(b);
		a--; b--;
		d[a][b] = true; d[b][a] = true;
	}
	
	bool visited[n];
	
	REP(i,n){visited[i]=false;}
	
	visited[0] = true;
	int ans = 0;
	ans = dfs(0,n,visited);
	PRINTD(ans);
	return 0;
}
	
