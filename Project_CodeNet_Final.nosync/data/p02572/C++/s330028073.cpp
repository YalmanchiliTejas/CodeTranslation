#include <bits/stdc++.h>
#define ll long long int 
#define endl '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 100000000 
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ans=0,s=0,c=0,t;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	s+=a[i];
    }
    for(int i=0;i<n;i++)
    {
    	c=(c+a[i]);
    	t=(s-c)%MOD;
    	t=((a[i]%MOD)*(t%MOD))%MOD;
    	//t=(a[i]*(s-c))%MOD;
    	ans=(ans+t)%MOD;
    }
    cout<<ans<<endl;
}
