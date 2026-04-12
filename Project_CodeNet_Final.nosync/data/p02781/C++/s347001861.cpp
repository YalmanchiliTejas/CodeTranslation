//----------BHAVIK DIWANI(PICT_COMP)---------------
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define MAX 1000005
#define pb push_back
#define vi vector<int>
#define endl '\n'
using namespace std;
// cnt total no. of elements between range from a to b which contains digit d exactly k times
string b;
int k;
vi num;
int dp[105][4][2];		//dp[pos][cnt][f]	f=if number has become less or not 
int call(int pos,int cnt,int f)
{
	if(cnt>k)
		return 0;
	if(num.size()==pos){
		if(cnt==k)
			return 1;
		return 0;
	}
	int limit,res=0;
	
	if(dp[pos][cnt][f]!=-1)
		return dp[pos][cnt][f];
	if(f==0)
		limit=num[pos];
	else
		limit=9;
		
	for(int i=0;i<=limit;i++)
	{
		int nf=f;
		int ncnt=cnt;
		if(i<limit)
			nf=1;
		if(i!=0)
			ncnt++;
		if(cnt<=k)
			res+=call(pos+1,ncnt,nf);
	}
	return dp[pos][cnt][f]=res;
}		

int solve(string b)
{
	num.clear();
	for(int i=0;i<b.length();i++)
	{
		num.pb(b[i]-'0');
	}
	memset(dp,-1,sizeof(dp));
	int res=call(0,0,0);
	return res;
}
signed main()
{
	fastio;
	cin>>b>>k;
	int res=solve(b);
	cout<<res<<endl;
	return 0;
}


