#include <iostream>
#include <cstring>
#define MAXN 3002

using namespace std;

int N;							//Number of numbers in set
int a[MAXN];					//Set of numbers
long long dp[MAXN][MAXN];	//dp[i][j] corresponds to maximum score obtained, when the gaame is played on [i,j]
bool cal[MAXN][MAXN];		//memoisation table to avoid extra calculations

long long solve(int i,int j){
	if(cal[i][j]==false){
		if(i==j)
			dp[i][j] = a[i];
		else
			dp[i][j] = max(a[i]-solve(i+1,j),a[j]-solve(i,j-1));
		cal[i][j]=true;
	}
	return dp[i][j];
}

int main(){
	cin>>N;
	
	for(int i=0;i<N;i++)
		cin>>a[i];

	memset(cal,false,N*N);

	cout<<solve(0,N-1)<<endl;
}
