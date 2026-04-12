	#include<bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	#define pb push_back
	#define mp make_pair
	#define sz(a) ll(a.size())
	#define trace(c,x) for(auto &x:c)
	#define F first
	#define S second		
	ll mod = 1e9 + 7;   //change acc to question

ll fastexpo(ll x,ll y)
{
	ll a=1;
	while(y>0)
	{
		if(y&1)a = (a*x)%mod;
		y/=2;
		x=(x*x)%mod;
	}	
	return a;
}

ll memo[3003][3003][2];
ll a[3003];
int n;

ll dp(int i,int j,int turn)
{
	if(i==j)
	{
		if(turn==0)
			return a[i];
		else
			return -a[i];
	}

	if(memo[i][j][turn]!=-1)
		return memo[i][j][turn];
	if(turn==0)
		memo[i][j][turn] =  max(a[i]+dp(i+1,j,1),a[j]+dp(i,j-1,1));
	else
		memo[i][j][turn] = min(-a[i]+dp(i+1,j,0),-a[j]+dp(i,j-1,0));
	
	return memo[i][j][turn];
}


int main()
{

	ios::sync_with_stdio(false);

	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<3003;i++)
		for(int j=0;j<3003;j++)
			for(int k=0;k<2;k++)
				memo[i][j][k] = -1;

	cout<<dp(0,n-1,0)<<endl;

	return 0;

	}	