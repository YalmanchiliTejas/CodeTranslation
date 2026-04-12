/*i-=-1*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define in(n) for(int i=0;i<n;i++)
#define inj(n) for(int j=0;j<n;j++)
#define itn int
#define ll long long 
#define ull unsigned ll
#define int ll int
#define S second 
#define F first 
#define mod 1000000007
#define globalbool 2000000
#define pii pair<int,int>
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using namespace std::chrono;
int dp[3001][3001]={0};
int n;
int ans=0;
int winningStratergy(itn A[],int st=0,int end=n-1,int chance=0)
{
	if(st>end)
		return 0;
	if(dp[st][end]!=0)
		return dp[st][end];
	//if(chance==0)
	//{
		int a=A[st]-winningStratergy(A,st+1,end,1);
		int b=A[end]-winningStratergy(A,st,end-1,1);
		dp[st][end]=max(a,b);
		return dp[st][end];
	//}
	//else
	//{

	//}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	auto start = high_resolution_clock::now();
	//int n;
	cin>>n;
	int A[n];
	in(n)
		cin>>A[i];
	itn sum=accumulate(A,A+n,0ll);
	cout<<winningStratergy(A);
	auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start); 
  
    //cout << "Time taken by function: "
    //<< duration.count() << " microseconds" << endl;
}