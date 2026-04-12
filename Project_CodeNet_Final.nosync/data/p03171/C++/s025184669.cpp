#include<iostream>
#include<algorithm>
using namespace std;
using lint=int64_t;

lint a[3010]={};
lint dp[3010][3010];
bool visited[3010][3010];

lint rec(int l,int r,int turn)
{
	if(l==r)
		return 0;
	
	if(visited[l][r])
		return dp[l][r];

	// turn of first
	lint ret=0;
	if(turn==1)
		ret=max(rec(l+1,r,-turn)+a[l],rec(l,r-1,-turn)+a[r-1]);
	else // turn of second
		ret=min(rec(l+1,r,-turn)-a[l],rec(l,r-1,-turn)-a[r-1]);

	dp[l][r]=ret;
	visited[l][r]=true;
	return ret;
}

int main()
{
	int N;

	cin >> N;
	for(int i=0;i<N;i++)
		cin >> a[i];

	cout << rec(0,N,1) << endl;
	return 0;
}
