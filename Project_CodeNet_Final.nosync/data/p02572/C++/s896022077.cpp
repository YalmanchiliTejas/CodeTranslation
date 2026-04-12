	/**
	*    author:  accesss_denied
	**/
	#include <bits/stdc++.h>
	using namespace std;
	#define ll long long int
	#define ff first
	#define ss second
	#define pb push_back
	#define endl "\n"
	#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll mod=1e9+7;			
	ll inf=1e18;

	int main() {
				fast
				// #ifndef ONLINE_JUDGE
				// freopen("input.txt","r",stdin);
				// freopen("output.txt","w",stdout);
				// #endif

				ll t;
				t=1;
				while(t--)
				{
					ll n;
					cin>>n;
					ll arr[n];
					ll sum=0;
					for(ll i=0;i<n;i++)
					{
					cin>>arr[i];
					sum=(sum%mod+arr[i]%mod)%mod;
					}
					ll prefix[n]={0};
					prefix[n-1]=(arr[n-1]%mod);
					for(ll i=n-2;i>=0;i--)
					{
						prefix[i]=(arr[i]%mod + prefix [i+1]%mod)%mod;
					}
					

					ll ans=0;

					for(ll i=0;i<n-1;i++)
					{
						sum=prefix[i+1];
						sum=(sum%mod);
						ll temp=(arr[i]%mod * sum%mod)%mod;
						ans=(ans%mod + temp%mod)%mod;
						
					}
					ans=ans%mod;
					cout<<ans;
					
				}
				return 0;
			}	


