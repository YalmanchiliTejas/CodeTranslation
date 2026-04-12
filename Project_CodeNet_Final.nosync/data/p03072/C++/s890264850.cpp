/***********************
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++) 
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

int n,a[100],ans=0;

int main()
{
	cin>>n;
	rep(i,n) cin>>a[i];
	rep(i,n)
	{
		bool ok=true;
		for(int j=0;j<i;j++) if(a[j]>a[i]) ok=false;
		if(ok) ans++;
	}
	cout<<ans<<endl;
	rt0;
}