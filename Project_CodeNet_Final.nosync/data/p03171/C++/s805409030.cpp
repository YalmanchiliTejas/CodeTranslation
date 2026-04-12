#include<bits/stdc++.h>
using namespace std;
long long DP[3001][3001],X[3001];
int N;
inline long long DFS(int S,int E)
{
	if(S>E)
		return 0;
	if(DP[S][E]!=-9099999999999999999)
		return DP[S][E];
	if((N-E+S-1)%2==0)
		return DP[S][E]=max(X[S]+DFS(S+1,E),X[E]+DFS(S,E-1));
	return DP[S][E]=min(DFS(S+1,E)-X[S],DFS(S,E-1)-X[E]);
}
int main()
{
	for(int i=0;i<3001;i++)
		for(int j=0;j<3001;j++)
			DP[i][j]=-9099999999999999999;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>X[i];
	cout<<DFS(0,N-1)<<endl;
	return 0;
}