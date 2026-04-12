/*suri_kumkaran*/

#include <bits/stdc++.h>

using namespace std;

#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define MP make_pair
#define EB emplace_back
#define endl "\n"
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

typedef long long int64;
typedef vector<int> VI64;
typedef vector<pair<int,int>> VII64;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;

int dp[200005][3][2];
bool cdp[200005][3][2];
int a[200005];
int n;

int suri(int idx,int extra,bool prev)
{
	if(extra>=3)
		return -1e15;
	if(idx==n)
		return 0;
	int &ans=dp[idx][extra][prev];
	if(cdp[idx][extra][prev])
		return ans;
	cdp[idx][extra][prev]=true;
	if(prev)
	{
		ans=suri(idx+1,extra,0);
	}
	else
	{
		ans=a[idx]+suri(idx+1,extra,1);
		ans=max(ans,suri(idx+1,extra+1,0));
	}
	return ans;
}


int32_t main()
{
	IOS;
	int T=1;
	//cin>>T;
	while(T--)
	{
		int i;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<suri(0,!(n&1),0);
		
	}

	return 0;
}