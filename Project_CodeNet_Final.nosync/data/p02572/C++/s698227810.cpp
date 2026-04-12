#include<bits/stdc++.h>
#define ll long long
#define pi acos(-1.0)
#define pb push_back
#define vi vector<int>
#define mapii map<int , int>
#define mapci map<char, int>
#define mapsi map<string,int>
#define FOR(i,n) for(int i = 0;i<n;i++)
#define CP(n) cout<<"Case "<<n<<": "
#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
#define MAX 1000007
#define all(x)(x.begin(),x.end())
#define debug(x,c) cout<<x<<": "<<c<<" ";
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
int main()
{
	int n;
	cin>>n;
	ll a[n];
	ll cum[n+1];
	cum[0] = 0;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		cum[i+1] = cum[i]+a[i];
	}
	ll sum = 0;
	ll mod = 1e9 + 7;
	for(int i = 1;i<n;i++)
	{
		sum+=((((a[i-1]%mod)*((cum[n]-cum[i])%mod)))%mod);
		sum%=mod;
	}
	cout<<sum<<endl;
	return 0;
}
