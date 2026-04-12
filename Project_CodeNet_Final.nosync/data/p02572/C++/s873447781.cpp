#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define endl "\n"
#define pi 3.14159265358979323846264338327950288
#define MOD 1000000007
#define INF -100000000000000
#define ordered_set tree<pair< ll int ,ll  int>, null_type,less<pair<ll int, ll int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define lld long double
using namespace __gnu_pbds;
int main()
{
    fast;
    ll int n;
    cin>>n;
    ll int a[n];
    ll int i,val=0,w,q,ans=0;
    for(i=0;i<n;i++)
    	cin>>a[i];

    ll int s[n];
    s[0]=a[0];
    for(i=1;i<n;i++)
    {
    	s[i]=s[i-1]+a[i];
    }
    val=s[n-1];
    for(i=0;i<n;i++)
    {
    	w=val-s[i];
    	q=((w%MOD)*(a[i]%MOD))%MOD;
    	ans=(ans%MOD+q%MOD)%MOD;
    }
    cout<<ans<<endl;
}