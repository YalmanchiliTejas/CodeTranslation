#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,x,n) for(ll i=x;i<n;i++)
#define S(v) sort(v.begin(), v.end())
#define SS(v) sort(v.begin(), v.end(), greater<int>())
#define print(v) for(auto i:v)cout<<i<<" "


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	// freopen("in.txt","r", stdin);
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll n, x, m,ans =0;
		cin>>n>>x>>m;
		map<ll,vector<ll>> mp;
		vector<ll> v;
		v.push_back(0);
		loop(i,0,n){
			ans += x;
			mp[x].push_back(i);
			v.push_back(ans);
			// cout<<x<<" ";
			if(mp[x].size()>1)	{
				ll j = mp[x][0];
				ll k = i - j;
				ans += ((n-i-1)/k)*(v[i] - v[j]);
			 	ans += v[j+1+(n-i-1)%k] - v[j+1];
				// ans = ans%m;
				break;
			}
			x = (x%m * x%m)%m;					
		}
		// cout<<endl;
		// print(v);
		cout<<ans<<endl;
	}
	
} 



