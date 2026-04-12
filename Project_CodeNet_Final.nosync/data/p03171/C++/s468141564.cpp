#include <bits/stdc++.h>
using namespace std;

int z;
long long dp[3005][3005];
long long arr[3005];

long long rekur(int a,int s)
{
	if(s-a==1)return max(arr[a],arr[s]);
	if(s-a==0)return arr[a];
	if(dp[a][s]!=-1)return dp[a][s];
	
	dp[a][s]=0;
	
	dp[a][s]=max(arr[a]+min(rekur(a+2,s),rekur(a+1,s-1)), arr[s]+min(rekur(a+1,s-1),rekur(a,s-2)));
	return dp[a][s];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));
	cin>>z;
	long long total=0;
	for(int q=1;q<=z;q++)
	{
		cin>>arr[q];
		total+=arr[q];
	}
	
	long long asd=rekur(1,z);
	long long dsa=total-asd;
	asd=asd-dsa;
	cout<<asd<<endl;
}