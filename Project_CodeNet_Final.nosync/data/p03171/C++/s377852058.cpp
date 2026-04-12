#include<stdio.h>
#include<iostream>
#include<string.h>
#include <iomanip>
#include<math.h>
#include<queue>
#include<vector>
#define Max (int)3e3+10
#define MAX_INT (int)1e17+2
#define MOD ((int)1e9+7)
using namespace std;

long long int dp[Max][Max];
int vis[Max][Max];

void init(){
	int i,j;
	for(i=0;i<Max;i++)
		for(j=0;j<Max;j++)
			vis[i][j] = 0;
}

long long int getMax(long long int a,long long int b){
	return a<b?b:a;
}

long long int getMin(long long int a,long long int b){
	return a<b?a:b;
}

long long int solve(int i,int j,long long int a[]){
	if(i+1 == j)
		return getMax(a[i],a[j]);
	else if(i == j)
		return a[i];
	if(vis[i][j] != 0)
		return dp[i][j];

	long long int min1;
	if(i+1 <= j-1)
		min1 = solve(i+1,j-1,a);
	else
		min1 = MAX_INT;
	if(i+2 <= j)
		min1 = getMin(solve(i+2,j,a),min1);
	else{
		if(min1 == MAX_INT)
			min1 = 0;
	}

	long long int min2 = MAX_INT;
	if(i <= j-2)
		min2 = solve(i,j-2,a);
	else
		min2 = 0;
	if(i+1 <= j-1)
		min2 = getMin(solve(i+1,j-1,a),min2);
	else{
		if(min2 == MAX_INT)
			min2 = 0;
	}

	long long int t1 = a[i]+min1;
	long long int t2 = a[j]+min2;
	//printf("LOG %lld %lld\n",t1,t2);
	dp[i][j] = getMax(t1,t2);
	vis[i][j] = 1;
	return dp[i][j];
}

int main(){
	int n,i;
	long long int a[Max],total = 0;
	init();
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		total += a[i];
	}

	long long int p1 = solve(0,n-1,a);
	long long int val = p1-(total-p1);
	printf("%lld\n",val);
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