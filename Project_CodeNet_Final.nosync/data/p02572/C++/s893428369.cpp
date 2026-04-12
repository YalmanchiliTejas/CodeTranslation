#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define bs binary_search
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define For(i,a,b) for(int i=a; i>=b ;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define setprec(x) cout << fixed << setprecision(x);
#define one(x) __builtin_popcount(x)
#define endl "\n"
#define mod 1000000007

int main()
{
	ll int n;
	cin>>n;
	ll int arr[n+1];
	FOR(i,0,n) cin>>arr[i];
	ll int ans=0, sum=0;
	FOR(i,0,n) 
	{
		sum+=arr[i];
		sum%=mod;
	}
	FOR(i,0,n-1)
	{
		sum-=arr[i];
		if(sum<0)
			sum+=mod;
		ans+=arr[i]*sum;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}