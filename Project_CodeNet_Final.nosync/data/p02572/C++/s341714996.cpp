#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) rep2(i,0,n)
#define FOR(i) for(cin>>i;i>0;i--)
#define elif else if
#define pb push_back
#define ll long long
#define mp make_pair
#define all(x) x.begin(),x.end()
#define re(x) {cout<<x<<endl;return 0;}
//#define x first
//#define y second

using namespace std;
ll n,a[222222],e[222222];
ll ans=0;
int main()
{
	cin>>n>>a[0];
	e[0]=0;
	rep2(i,1,n)
	{
		cin>>a[i];
		e[i]=(a[i-1]+e[i-1])%1000000007;
	}
	rep(i,n)
	{
		ans+=(a[i]*e[i])%1000000007;
		ans%=1000000007; 
	}
	re(ans)
	return 0;}