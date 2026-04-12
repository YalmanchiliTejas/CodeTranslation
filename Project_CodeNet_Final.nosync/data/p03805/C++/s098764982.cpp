//I_F_A
#include "bits/stdc++.h"
using namespace std;

long long n,m;
bool graph[12][12];
long long ans = 0;

bool dfs(long long *arr){

	if(arr[1] != 1)
		return 0;

	long long src = arr[1];
	for(long long i=2;i<=n;i++){

		if(graph[arr[i]][arr[i-1]] != 1){

			return 0;
		}
	}
	return 1;
}


void func(long long index,long long *arr,bool *visited){

	if(index == n+1){

		if(dfs(arr))
			ans++;
	}
	else{

		for(long long i=1;i<=n;i++){

			if(visited[i] == 0){

				visited[i] = 1;
				arr[index] = i;
				func(index+1,arr,visited);
				visited[i] = 0;
			}
		}
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			graph[i][j] = 0;

	for(long long i=1;i<=m;i++){

		long long a,b;
		cin >> a >> b;

		graph[a][b] = graph[b][a] = 1;
	}


	long long arr[n+1];
	bool visited[n+1];
	
	for(long long i=1;i<=n;i++)
		visited[i] = 0;

	func(1LL,arr,visited);

	cout << ans << endl;
}