#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define m_p			make_pair
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i =a, i>=b;i--)
#define sz(x)       (int)x.size()
#define F			first
#define S			second
#define debug(x)	for(int i=0;i<x;i++) cout<<"##########"<<endl
#define M			1000000007
#define ll			long long int
#define lMax		LLONG_MAX
#define pii 		pair<int ,int >
#define	all(a)		a.begin(), a.end()
#define vi 			vector<int> 
#define vii 		vector<pii>

// queue<int> , prefix_sum(a,a+n) , reverse(a,a+n) , priority_queue <int> max heap , priority_queue <int, vector<int>, greater<int> > min heap;
// == > != precedence gretaer then & , << precedence greater than <= == => , 
//int chk, cnt, fl, pos, in, src, tar, val, res. dummy;  fill (myvector.begin(),myvector.begin()+4,5), freq;

const int nmax=305;

void solve()
{
	ll n;
	cin>>n;
	
	ll arr[n+1];
	ll pre[n+1]={0};
	rep(i,1,n+1) cin>>arr[i],pre[i]=pre[i-1]+arr[i];
	
	pair<ll,ll> dp[n+1][n+1];
//	rep(i,0,n+1) cout<<pre[i]<<" ";
//	cout<<endl;
	for(int size=1;size<=n;size++)
	{
		for(int i=1;i+size-1<=n;i++)
		{
			if(size==1) dp[i][i]=m_p(arr[i],0);
			else 
			{
				ll j=i+size-1;
				ll x=max(arr[i]+dp[i+1][j].S,arr[j]+dp[i][j-1].S);
				dp[i][j]=m_p(x,pre[j]-pre[i-1]-x);
			}
		}
	}
//	rep(i,1,n+1)
//	{
//		rep(j,1,n+1)
//		{
//			cout<<dp[i][j].F<<" ";
//		}
//		cout<<endl;
//	}
	cout<<2*dp[1][n].F-pre[n]<<endl;
}


signed main()
{
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int t=1;
		while(t--)
		{
			solve();
		}
}