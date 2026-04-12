#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
vector < int > v[N];
int dfs(int node , int parent){
	int tot = 0;
	for(int next : v[node]){
		if(next != parent){
			tot += dfs(next , node);
		}
	}
	if(tot > 1){
		printf("First\n");
		exit(0);
	}
	return !tot;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		int a , b;
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	if(dfs(1 , 0)){
		printf("First\n");
	}
	else{
		printf("Second\n");
	}
}