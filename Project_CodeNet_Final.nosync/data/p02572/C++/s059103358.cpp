#include<bits/stdc++.h>                                                   //---------------------------------------------------------------

# define ll long long
# define mod 1000000007
# define MAX 100005
# define PI 3.141592653589793238                                                                                  //shortcut keys

# define pb push_back
# define mp make_pair
# define all(x) x.begin(),x.end()
# define fr(i,a,b) for(int i=a;i<=b;i++)

# define decimal(k) fixed<<setprecision(k)
# define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);        //---------------------------------------------------------------
using namespace std;

int main()
{
	
	int n;cin>>n;
	ll a[n+1];fr(i,1,n)cin>>a[i];
	ll sum=0;
	//fr(i,1,n)sum+=a[i];
	ll ans=0;
	for(int i=n;i>=1;i--){
		ans=(ans+(a[i]*(sum%mod))%mod)%mod;
		sum+=a[i];
	}
	cout<<ans<<"\n";

	return 0;
}

