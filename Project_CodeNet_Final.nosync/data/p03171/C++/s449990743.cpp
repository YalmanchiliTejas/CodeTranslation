#include <bits/stdc++.h>
using namespace std;

deque<int> q;

long long dp[3000+1][3000+1];
bool visited[3000+1][3000+1]={};

long long ans(long long turn,long long start,long long end,long long a){
	if(start>end)
	return a;
	if(visited[start][end])
	return a+dp[start][end];
	long long b;
		if(turn==0)
		b=max(ans(1-turn,start+1,end,a+q[start]),ans(1-turn,start,end-1,a+q[end]));
		else
		b=min(ans(1-turn,start+1,end,a-q[start]),ans(1-turn,start,end-1,a-q[end]));
		dp[start][end]=b-a;
		visited[start][end]=true;
		return dp[start][end]+a;
}


int main() {
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		q.push_back(a);
	}
	cout<<ans(0,0,n-1,0)<<endl;
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	return 0;
}