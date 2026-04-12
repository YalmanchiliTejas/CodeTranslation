#include<bits/stdc++.h>
#define ll long long int
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define rep(n) for(ll i2=0;i2<n;i2++)
#define vmp(v,a,b) v.push_back(make_pair(a,b))
#define si(a) scanf("%lld",&a)
#define pi(a) printf("%lld",a)
#define aset(a,n,k) for(ll i3=0;i3<n;i3++)a[i3]=k; 	
#define mod 1000000007
#define mp(a,b) make_pair(a,b)
#define f first
#define s second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_orde(ind)
using namespace std;
int main()
{
	sync;
	ll n,k;
	string s;
	cin>>n>>s>>k;
	for(ll i=0;i<n;i++)
	if(s[i]!=s[k-1])
	s[i]='*';
	cout<<s;
}