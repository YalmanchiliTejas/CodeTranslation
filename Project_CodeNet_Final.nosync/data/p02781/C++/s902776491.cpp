//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pf pop_front
#define mp make_pair
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define fo(i,n) for(int i=0;i<(n);i++)
#define inp(a) int a;cin>>a;
#define inpa(a,n)vector<int> a(n);fo(i,n)cin>>a[i];
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
using namespace std;
#define int ll
// #define MAX 20
#define INF (int)1e18

template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.F<<','<< P.S<<')';}


signed main()
{
	fio
	string s;cin>>s;inp(x)
	int n=s.size();
	int nxt[n+1];
	nxt[n]=n;
	for(int i=n-1;i>=0;i--)
	{
		nxt[i]=nxt[i+1];
		if(s[i]!='0')
			nxt[i]=i;
	}
	// fo(i,n)
	// 	cout<<nxt[i]<<' ';
	// cout<<'\n';
	int ans=0;
	if(x==3)
	{
		fo(i,n)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					if(i)
					{
						ans+=9*9*9;
					}
					else
					{
						ans+=(max(0,s[i]-'0'-1))*9*9;
						if(s[i]=='0')
							continue;
						if(j<=nxt[i+1])
						{
							ans+=(max(0,s[j]-'0'-1))*9;
							if(s[j]=='0')
								continue;
							if(nxt[j+1]>=k)
							{
								ans+=s[k]-'0';
							}
							else
							{
								ans+=9;
							}
						}
						else
						{
							ans+=9*9;
						}
					}
				}
			}
		}
	}
	else if(x==2)
	{
		fo(i,n)
		{
			for(int j=i+1;j<n;j++)
			{
				if(i)
				{
					ans+=9*9;
				}
				else
				{
					ans+=max(s[i]-'0'-1,0)*9;
					if(s[i]=='0')
						continue;
					if(j<=nxt[i+1])
					{
						ans+=(s[j]-'0');
					}
					else
					{
						ans+=9;
					}
				}
			}
		}
	}
	else
	{
		fo(i,n)
		{
			
			if(i)
			{
				ans+=9;
			}
			else
			{
				ans+=(s[i]-'0');
			}
		}
	}
	cout<<ans<<'\n';
	printclock;
}