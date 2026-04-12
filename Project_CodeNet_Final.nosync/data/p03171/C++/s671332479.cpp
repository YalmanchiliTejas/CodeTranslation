#include <bits/stdc++.h>
using namespace std;
long long int n, x, memo[3010][3010];
bool visited[3010][3010];
vector<long long int>arr(3010);

long long int dp(long long int i, long long int j){
	if(visited[i][j]){
		return memo[i][j];
	}
	visited[i][j]=1;
	if(i==j){
		return memo[i][j]=arr[i];
	}
	return memo[i][j]=max(arr[i] - dp(i+1, j), arr[j] - dp(i, j-1));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	cout << dp(0, n-1) << endl;
}