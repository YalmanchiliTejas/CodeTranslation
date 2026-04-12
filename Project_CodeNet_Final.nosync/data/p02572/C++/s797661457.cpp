#include<bits/stdc++.h>
#define N 200005
#define M 1000000007
#define ll long long
#define ldb long double
#define pi acos(-1)
using namespace std;
ll n,k,l,r,a[N],b[N],ans,sum,ans1;
char s[N],t[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	b[0]=a[0];
	for(int i=1;i<n;i++)
	b[i]=(b[i-1]+a[i])%M;
	for(int i=1;i<n;i++)
	ans=(ans+a[i]*b[i-1])%M;
	cout<<ans;
	return 0;
}