#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define int long long
const int MOD=1e9+7;
const int N=3e5+10;
int a[N];
int pre[N];
int32_t main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		pre[i]=pre[i+1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n-1;i++)
	{
		int k=pre[i+1];
		k%=MOD;
		ans+=(k*a[i])%MOD;
		ans%=MOD;
	}
	cout<<ans<<endl;


}