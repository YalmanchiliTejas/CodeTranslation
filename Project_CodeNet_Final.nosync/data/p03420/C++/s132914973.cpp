#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#define size 500010
#define debug(x) cerr<<#x<<"="<<x
#define gc getchar()
#define db double
#define ll long long
#define rep(i,s,n) for (register int i=s;i<=n;i++)
#define drep(i,n,s) for (register int i=n;i>=s;i--)
#define il inline
using namespace std;

il ll r()
{
	char c; ll x,f=1;
	for (c=gc;!isdigit(c);c=gc) if (c=='-') f=-1; x=c-'0';
	for (c=gc;isdigit(c);c=gc) x=(x<<1)+(x<<3)+c-'0';
	return f*x;
}

ll n,k,ans=0;

int main()
{
	n=r(); k=r(); if (!k) {cout<<1ll*n*n<<endl; return 0;}
	rep(i,k+1,n)
	 	ans+=(n/i)*(i-k) +max(n%i-(k-1),1ll*0);	
	cout<<ans<<endl;
	return 0;
}
















