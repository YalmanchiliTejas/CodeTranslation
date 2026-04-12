#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops") 
#include<bits/stdc++.h>
 
#define ll 			long long int 
#define pb          push_back
#define	endl		'\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define dep(i,a,b)	for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;
 
#define N  105
ll mod=1e9+7;
 ll dp[10005][105][2];
 string s;
 int n;
 int d;
 int rec(int i, int rem, int flag)
 {
 	if(i==n)
 	{
 		if(rem==0)
 			return 1;
 		return 0;

 	}
 	ll &res=dp[i][rem][flag];
 	if(res!=-1)
 		return res;
 	res=0;
 	if(flag)
 	{
 		for(int j=0;j<=s[i]-'0';j++)
 		{
 			if(j==s[i]-'0')
 				res=(res+rec(i+1,(rem+j)%d,true))%mod;
 			else
 				res=(res+rec(i+1,(rem+j)%d,false))%mod;
 		}
 	}
 	else
 	{
 		for(int j=0;j<=9;j++)
 		{
 			
 				res=(res+rec(i+1,(rem+j)%d,false))%mod;
 		}

 	}
 	return res;
 }
void solve()
{

	memset(dp,-1,sizeof(dp));
	
	
	cin>>s;
	n=s.length();
	//int d;
	cin>>d;
	cout<<(rec(0,0,1)%mod-1%mod+mod)%mod;
	

}
	
	
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
    	
    
   //cin>>TESTS;
	int p=1;
	while(TESTS--)
	{
		//cout<<"CASE #"<<p<<":"<<" ";
		solve();
		p++;
		
		
	}
	return 0;
}