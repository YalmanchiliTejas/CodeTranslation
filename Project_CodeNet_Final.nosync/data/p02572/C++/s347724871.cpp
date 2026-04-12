#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<stdio.h>
#include<cmath>
#include<math.h>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<sstream>
#include<iomanip>
#define forn(i,n) for(int (i)=0;i<(n);i++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MAXN=100005;
const int INF=2147483647;
const ll LINF=9223372036854775807;
const ll Mod=1000000007;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n;
ll a[200005],sum,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	forn(i,n)
	{
		cin>>a[i];
		sum+=a[i];
		sum%=Mod;
	}
	forn(i,n)
	{
		sum-=a[i];
		if(sum<0)sum+=Mod;
		ans+=a[i]*sum;
		ans%=Mod;
	}
	cout<<ans;
	return 0;
}
