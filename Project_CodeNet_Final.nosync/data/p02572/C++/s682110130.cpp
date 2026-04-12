#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define uii             unordered_map<int,int>
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
void S_K_S()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


int32_t main()
{
	S_K_S();
	int n;
	cin >> n;
	int a[n], sum = 0,ans=0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		ans+=a[i]*sum;
		ans%=mod;
		sum+=a[i];
		sum%=mod;
	}
	cout<<ans;
}
