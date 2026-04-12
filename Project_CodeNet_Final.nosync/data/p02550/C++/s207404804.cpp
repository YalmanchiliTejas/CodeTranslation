#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree < pairs ,  null_type , greater<pairs>,  rb_tree_tag ,  tree_order_statistics_node_update > 
#define ll long long
#define lld long double
#define vc vector<ll>
const ll MOD=(1e9 +7);
typedef pair<ll,ll>pairs;
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;b--;}a=(a*a)%MOD;b>>=1;}
    return res;}

int main() {
	// your code goes here
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll t,n,i,j,k,m,c,f,pre,ans;
	map<ll,ll>mp;
	cin>>n>>pre>>m;ans=pre;
	i=f=1;mp[pre]=1;vc v;v.push_back(0);v.push_back(pre);
	while((pre*pre)%m>0&&i<n)
	{
	    //ans+=(pre*pre)%m;
	    pre=(pre*pre)%m;
	    if(mp[pre]){f=0;break;}
	    ans+=pre;
	    i++;
	    mp[pre]=i;
	    v.push_back(v[i-1]+pre);

	}
	if(!f)
	{
	    ll ind=mp[pre];
	    ll len=i-mp[pre]+1;
	    ans+=((n-i)/len)*(v[i]-v[ind-1]);
	    ll rem=(n-i)%len;
	    for(i=ind;i-ind<rem;i++)ans+=v[i]-v[i-1];
	}
	cout<<ans;
	return 0;
}
