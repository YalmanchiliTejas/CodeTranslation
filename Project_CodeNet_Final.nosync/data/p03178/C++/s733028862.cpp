#include<bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
#define int ll


#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define mp make_pair
#define ub(a,b) upper_bound(all(a),b)
#define lb(a,b) lower_bound(all(a),b)
#define bs(a,b) binary_search(all(a),b)
#define mem(a,b) memset(a,b,sizeof(a))
#define in(a,n) f(i,0,n-1)cin>>a[i]
#define in1(a,n) f(i,1,n)cin>>a[i]
#define out(a,n) f(i,0,n-1)cout<<fixed<<setprecision(20)<<a[i]<<" ";cout<<"\n"
#define ff first
#define ss second
#define f(i,a,b) for (int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,n) f(i,0,n-1)
#define clr(a) (a).clear()
#define rz resize
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin() ,(a).rend()
#define endl '\n'

const int M=(int)1e9+7;

string num;
int n,d;

ll dp[10005][2][105][2];
bool vis[10005][2][105][2];

ll go(int pos, int f, int sum, int start)
{
	if (pos==n)
	{
		if (sum==0)
			return 1;
		else
			return 0;
	}

	ll &ans=dp[pos][f][sum][start];

	if (vis[pos][f][sum][start])
		return ans;

	vis[pos][f][sum][start]=true;
	ans=0LL;

	int LMT=(f)? 9 : num[pos]-'0';

	if (!start)
	{
		f(i,0,LMT)
		{
			int nf=1;
			if (f==0 && i==LMT)nf=0;
			ans=(ans+go(pos+1,nf,(sum+i)%d,start))%M;
		}
	}
	else
	{
		f(i,1,LMT)
		{
			int nf=1;
			if (f==0 && i==LMT)nf=0;
			ans=(ans+go(pos+1,nf,(sum+i)%d,0))%M;
		}
		ans=(ans+go(pos+1,1,sum%d,1))%M;
	}

	return ans;
} 

ll dp1[1005][2][9055][2];
bool vis1[1005][2][9055][2];
 
ll go1(int pos, int f, int sum, int start)
{
	if (pos==n)
	{
		if (sum%d==0 && sum > 0LL)
			return 1;
		else
			return 0;
	}
 
	ll &ans=dp1[pos][f][sum][start];
 
	if (vis1[pos][f][sum][start])
		return ans;
 
	vis1[pos][f][sum][start]=true;
	ans=0LL;
 
	int LMT=(f)? 9 : num[pos]-'0';
 
	if (!start)
	{
		f(i,0,LMT)
		{
			int nf=1;
			if (f==0 && i==LMT)nf=0;
			ans=(ans+go1(pos+1,nf,sum+i,start))%M;
		}
	}
	else
	{
		f(i,1,LMT)
		{
			int nf=1;
			if (f==0 && i==LMT)nf=0;
			ans=(ans+go1(pos+1,nf,sum+i,0))%M;
		}
		ans=(ans+go1(pos+1,1,sum,1))%M;
	}
 
	return ans;
 
 
}

signed main(int argc, char const *argv[])
{
	crap;
	cin>>num;
	n=num.length();
	cin>>d;
	if (n>=1005)
		cout<<go(0,0,0LL,1)-1<<endl;
	else
		cout<<go1(0,0,0,1)<<endl;
	return 0;
}