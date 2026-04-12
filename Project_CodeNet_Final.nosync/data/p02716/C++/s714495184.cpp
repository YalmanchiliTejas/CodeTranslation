#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<queue>
#define mem(x) memset(x,0,sizeof(x)) 
#define sca(x) scanf("%d",&x)
#define scaa(x,y) scanf("%d%d",&x,&y)
#define inf 0x7f7f7f7f
#define io ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#pragma GCC optimize(2)
using namespace std;
const double pi=acos(-1); 
const double eps=1e-6;
typedef pair<long,long> pll;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<char,char> pcc;
const ll p=1e9+7;
ll a[200005];
ll f[200005],s[200005];
int main()
{
	ll n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i%2==1)
		s[i]=s[i-1]+a[i];
		else
		s[i]=s[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		if(i%2==1)
		{
			f[i]=max(f[i-2]+a[i],f[i-1]);
		}
		else
		f[i]=max(f[i-2]+a[i],s[i-1]);
	}
	cout<<f[n]<<endl;
}