#include<stdio.h>
#include<iostream>
#include<string.h>
#include <iomanip>
#include<math.h>
#include<queue>
#include<vector>
#include<algorithm>
#define Max (int)105
#define MAX2 (int)1e5+5
#define MOD ((int)1e9+7)
using namespace std;



int main(){
	int n,i,a[Max];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	int max = 0,tmp = 0;
	for(i=0;i<n;i++){
		if(a[i]>=max){
			max = a[i];
			tmp++;
		}
	}

	printf("%d\n",tmp);
}










/*
Atcoder Dp G-Longest Path iterative solution

vector<int>vec[Max];
queue<int>q;

int dp[Max];
int vis[Max];

void init(){
	int i;
	for(i=0;i<Max;i++){
		dp[i] = 0;
		vis[i] = 0;
	}
}

int getMax(int a,int b){
	return (a<b)?b:a;
}

void solve(int x){
	int i,u;
	q.push(x);

	while(!q.empty()){
		u = q.front();
		q.pop();

		if(vis[u])
			continue;
		vis[u] = 1;
		
		for(i=0;i<vec[u].size();i++){
			dp[vec[u][i]] = getMax(dp[vec[u][i]],dp[u]+1);
			q.push(vec[u][i]);
		}
	}

}

int main(){
	int n,m,incoming[Max],x,y,i;
	for(i=0;i<Max;i++)
		incoming[i] = 0;
	
	init();

	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		vec[y].push_back(x);
		incoming[x]++;
	}
	
	for(i=1;i<=n;i++)
		solve(i);
	
	int max = 0;
	for(i=0;i<Max;i++)
		max = getMax(max,dp[i]);
	
	printf("%d\n",max);
	return 0;
}
*/