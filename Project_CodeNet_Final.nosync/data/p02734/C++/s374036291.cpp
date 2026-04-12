//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pb push_back
#define inf 10000000000000000
#define N 998244353
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.x<<','<< P.y<<')';}
template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}


int f[3001][3001];
//edge cases when n=1 , m=1. wrong variable in loop. if<->while
signed main()
{
	speed
	//global var
	for(int i=0;i<3001;++i){f[0][i]=0;}
	
	int n,s;cin>>n>>s;

	vector<int> inp(n);
	for(int i=0;i<n;++i)
	{
		cin>>inp[i];
	}
	vector<int> prefix(s+1,0);
	if(s>=inp[0]){f[0][inp[0]]=1;prefix[inp[0]]=1;}
	
	
	int ans=0;
	for(int ix=1;ix<n;++ix)
	{
		for(int sum=s;sum>inp[ix];--sum)
		{
			f[ix][sum]=prefix[sum-inp[ix]];f[ix][sum]%=N;
			prefix[sum]+=f[ix][sum];prefix[sum]%=N;
		}
		if(s>=inp[ix]){f[ix][inp[ix]]=ix+1;prefix[inp[ix]]+=(ix+1);prefix[inp[ix]]%=N;}
		ans+=(f[ix][s]*(n-ix));
		ans%=N;
	}
	cout<<ans<<"\n";

}