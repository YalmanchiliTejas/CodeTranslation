#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>

ll INF = 1000000007;


//-----------------//
  #define amin main




int amin()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i,j;
	ll n;

	cin>>n;
	ll arr[n];
	ll suf[n]={0};
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	suf[0] = arr[n-1];
	j = 1;

	for(i=n-2;i>=0;i--)
	{

		suf[j] = (suf[j-1] + arr[i])%INF;
		j++;
		//cout<<suf[j]<<" "<<suf[j-1]<<" "<<arr[i]<<endl;
	}
	
	ll ans= 0;
	j = n-2;
	for(i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			ans += (arr[i]*suf[j])%INF;
			//cout<<arr[i]<<" "<<suf[j]<<endl;
		}
		j--;
		ans = ans%INF;
		//cout<<ans<<endl;
	}

ans = ans%INF;
cout<<ans<<endl;
	
	


	
	return 0;
}